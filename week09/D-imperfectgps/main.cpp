#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n, t;
    cin >> n >> t;
    double actual = 0.0, gps = 0.0;
    int xp, yp, tp;
    cin >> xp >> yp >> tp;
    double xg = xp, yg = yp;
    int tg = tp;
    for (int i = 1; i <= n; i++) {
        if (i < n) {
            int xi, yi, ti;
            cin >> xi >> yi >> ti;

            for (int tc = tg + t; tc <= ti; tc += t) {
                const double diff = static_cast<double>(tc - tp) / (ti - tp);
                const auto xc = xp + (xi - xp) * diff;
                const auto yc = yp + (yi - yp) * diff;
                gps += hypot(xc - xg, yc - yg);

                xg = xc, yg = yc;
            }
            actual += hypot(xi - xp, yi - yp);

            xp = xi, yp = yi, tp = ti;
            tg = (ti / t) * t;
        } else {
            gps += hypot(xp - xg, yp - yg);
        }
    }
    const auto diff = actual - gps;
    printf("%.10f\n", 100 * diff / actual);
    return 0;
}

#include <cmath>
#include <cstdio>
#include <iostream>
#include <numbers>
using namespace std;
using ll = long long;

int main() {
    using numbers::pi;
    for (ll a, b, s, m, n; cin >> a >> b >> s >> m >> n, a || b || s || m || n;) {
        const double vx = static_cast<double>(m) * a / s;
        const double vy = static_cast<double>(n) * b / s;

        const double speed = hypot(vx, vy);
        const double angle = (m == 0 && n == 0) ? 0.0 : atan2(vy, vx) * 180.0 / pi;

        printf("%.2f %.2f\n", angle, speed);
    }
    return 0;
}

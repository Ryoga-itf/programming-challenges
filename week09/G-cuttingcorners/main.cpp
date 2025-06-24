#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    constexpr double eps = 1e-10;
    using Point = pair<int, int>;
    const auto angle = [](const Point &pre, const Point &cur, const Point &nxt) -> double {
        const auto dot = [&](const Point &a, const Point &b) { return a.first * b.first + a.second * b.second; };
        const auto norm = [&](const Point &a) { return sqrt(dot(a, a)); };

        Point v1{pre.first - cur.first, pre.second - cur.second};
        Point v2{nxt.first - cur.first, nxt.second - cur.second};
        const double cosv = dot(v1, v2) / (norm(v1) * norm(v2));
        return acos(clamp(cosv, -1.0, 1.0));
    };
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<Point> poly(n);
        for (auto &[x, y] : poly) {
            cin >> x >> y;
        }
        while (poly.size() > 3) {
            int min_idx = -1;
            double min_angle = 1e100;
            const int m = poly.size();
            for (int i = 0; i < m; i++) {
                const int p = (i + m - 1) % m;
                const int q = (i + 1) % m;
                if (const auto ang = angle(poly[p], poly[i], poly[q]); ang < min_angle) {
                    min_angle = ang;
                    min_idx = i;
                }
            }

            double new_min_angle = 1e100;
            vector<Point> next_poly;
            next_poly.reserve(m - 1);
            for (int i = 0; i < m; i++) {
                if (i != min_idx) {
                    next_poly.push_back(poly[i]);
                }
            }
            const int tm = m - 1;
            for (int i = 0; i < tm; i++) {
                const int p = (i + tm - 1) % tm;
                const int q = (i + 1) % tm;
                if (const auto ang = angle(next_poly[p], next_poly[i], next_poly[q]); ang < new_min_angle) {
                    new_min_angle = ang;
                }
            }

            if (new_min_angle + eps < min_angle) {
                break;
            } else {
                poly.swap(next_poly);
            }
        }

        cout << poly.size();
        for (const auto &[x, y] : poly) {
            cout << ' ' << x << ' ' << y;
        }
        cout << endl;
    }
}

#include <cmath>
#include <iostream>
#include <numbers>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

struct Cmd {
    string op;
    string arg;
};

int main() {
    constexpr double eps = 1e-3;
    using numbers::pi;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Cmd> prog(n);
        int qidx = -1;
        for (int i = 0; i < n; i++) {
            cin >> prog[i].op >> prog[i].arg;
            if (prog[i].arg == "?") {
                qidx = i;
            }
        }
        const auto &qop = prog[qidx].op;

        if (qop == "fd" || qop == "bk") {
            double x = 0, y = 0;
            double dir = 0;
            double ux = 0, uy = 0;

            for (int i = 0; i < n; ++i) {
                const auto &op = prog[i].op;
                const auto &arg = prog[i].arg;

                if (arg == "?") {
                    const double rad = dir * pi / 180.0;
                    double cx = cos(rad), cy = sin(rad);
                    if (op == "bk") {
                        cx = -cx;
                        cy = -cy;
                    }
                    ux = cx, uy = cy;
                    continue;
                }

                const int v = stoi(arg);
                if (op == "fd" || op == "bk") {
                    const double sign = (op == "fd") ? 1 : -1;
                    const double rad = dir * pi / 180.0;
                    x += sign * v * cos(rad);
                    y += sign * v * sin(rad);
                } else {
                    const int ang = v % 360;
                    dir += ang * ((op == "lt") ? 1 : -1);
                }
            }

            const ll d = llround(-(x * ux + y * uy));
            cout << d << endl;
        } else {
            int ans = 0;
            for (int ang = 0; ang < 360; ++ang) {
                double x = 0, y = 0, dir = 0;

                for (int i = 0; i < n; ++i) {
                    const auto &op = prog[i].op;
                    const auto &arg = prog[i].arg;
                    const auto v = (arg == "?") ? ang : stoi(arg);

                    if (op == "fd" || op == "bk") {
                        const double sign = (op == "fd") ? 1 : -1;
                        const double rad = dir * pi / 180.0;
                        x += sign * v * cos(rad);
                        y += sign * v * sin(rad);
                    } else {
                        const int a = v % 360;
                        dir += a * ((op == "lt") ? 1 : -1);
                    }
                }
                if (hypot(x, y) < eps) {
                    ans = ang;
                    break;
                }
            }
            cout << ans << endl;
        }
    }
}

#include <cmath>
#include <cstdio>
#include <iostream>
#include <numbers>
using namespace std;
using ll = long long;

int main() {
    using numbers::pi;
    while (true) {
        int r, h, s;
        cin >> r >> h >> s;
        if (r + h + s == 0) {
            break;
        }
        const auto p = acos(static_cast<double>(r) / h) / pi;
        const auto l = 2 * r * numbers::pi * (1.0 - p) + 2 * sqrt(h * h - r * r);
        const auto ans = l * static_cast<double>(s + 100) / 100;
        printf("%.2f\n", ans);
    }
    return 0;
}

#include <algorithm>
#include <bit>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }
    double m;
    cin >> m;
    const auto ok = [&](double speed) {
        const auto speeds = [&]() {
            vector<double> res(n);
            res[0] = speed;
            for (int i = 1; i < n; i++) {
                res[i] = res[i - 1] * m;
            }
            return res;
        }();
        vector dp(1 << n, vector(n, 1e9));
        dp[0][0] = 0.0;
        for (int bit = 0; bit < (1 << n); bit++) {
            for (int from = 0; from < n; from++) {
                for (int to = 0; to < n; to++) {
                    if (bit != 0 and !(bit & (1 << from))) {
                        continue;
                    }
                    if ((bit & (1 << to)) == 0) {
                        if (bit != 0 and from == to) {
                            continue;
                        }
                        const auto xf = bit == 0 ? 0.0 : x[from], yf = bit == 0 ? 0.0 : y[from];
                        const int nxt = bit | (1 << to);
                        const double dist = hypot(x[to] - xf, y[to] - yf);
                        const auto cur = speeds[popcount(static_cast<unsigned>(bit))];
                        const double cost = dist / cur;
                        const auto time = dp[bit][from] + cost;
                        if (time <= s[to]) {
                            dp[nxt][to] = min(dp[nxt][to], dp[bit][from] + cost);
                        }
                    }
                }
            }
        }
        bool res = false;
        for (int i = 0; i < n; i++) {
            if (dp[(1 << n) - 1][i] != 1e9) {
                res = true;
            }
        }
        return res;
    };
    int t = 50;
    double left = 0.0, right = 1e9;
    while (t--) {
        const auto mid = (left + right) / 2.0;
        (ok(mid) ? right : left) = mid;
    }
    printf("%.16f\n", right);
    return 0;
}

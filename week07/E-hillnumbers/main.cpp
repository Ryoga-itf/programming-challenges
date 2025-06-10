#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    const string s = to_string(n);
    const auto digits = [&s]() {
        vector<int> res;
        res.reserve(s.size());
        for (const auto &c : s) {
            res.push_back(c - '0');
        }
        return res;
    }();
    const int m = s.size();
    // dp[i][j][d][t] = i 桁目まで見ているとき、最後が i で d (down) かどうか、t (桁DPでいうところのmaxかどうか)
    vector dp(m, vector(10, vector(2, vector(2, 0ll))));
    for (int i = 0; i <= digits[0]; i++) {
        dp[0][i][0][i == digits[0]]++;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int t = 0; t <= 9; t++) {
                if (t <= digits[i]) {
                    const auto p = t == digits[i];
                    if (j < t) {
                        dp[i][t][0][p] += dp[i - 1][j][0][1];
                    } else if (j > t) {
                        dp[i][t][1][p] += dp[i - 1][j][0][1];
                        dp[i][t][1][p] += dp[i - 1][j][1][1];
                    } else {
                        dp[i][t][0][p] += dp[i - 1][j][0][1];
                        dp[i][t][1][p] += dp[i - 1][j][1][1];
                    }
                }
                if (j < t) {
                    dp[i][t][0][0] += dp[i - 1][j][0][0];
                } else if (j > t) {
                    dp[i][t][1][0] += dp[i - 1][j][0][0];
                    dp[i][t][1][0] += dp[i - 1][j][1][0];
                } else {
                    dp[i][t][0][0] += dp[i - 1][j][0][0];
                    dp[i][t][1][0] += dp[i - 1][j][1][0];
                }
            }
        }
    }
    if (dp[m - 1][digits.back()][0][1] or dp[m - 1][digits.back()][1][1]) {
        ll ans = 0;
        for (int i = 0; i <= 9; i++) {
            ans += dp[m - 1][i][0][0] + dp[m - 1][i][0][1];
            ans += dp[m - 1][i][1][0] + dp[m - 1][i][1][1];
        }
        cout << ans - 1 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}

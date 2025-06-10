#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    const int n = s.size();
    vector dp(n, vector(n, 0));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    const auto prefix = [](const string &s) -> vector<int> {
        int m = s.size();
        vector<int> pi(m, 0);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 and s[i] != s[j]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
                pi[i] = j;
            }
        }
        return pi;
    };

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i + l <= n; i++) {
            const int j = i + l - 1;
            auto &best = dp[i][j];
            best = l;

            for (int k = i; k < j; k++) {
                best = min(best, dp[i][k] + dp[k + 1][j]);
            }

            string sub = s.substr(i, l);
            const auto pi = prefix(sub);
            const auto p = l - pi[l - 1];
            if (p < l and l % p == 0) {
                best = min(best, dp[i][i + p - 1]);
            }
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}

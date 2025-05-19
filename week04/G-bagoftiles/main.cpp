#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll cmb[31][31];
    for (int i = 0; i < 31; i++) {
        cmb[i][0] = cmb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            cmb[i][j] = cmb[i - 1][j - 1] + cmb[i - 1][j];
        }
    }

    int g;
    cin >> g;
    for (int game = 1; game <= g; game++) {
        int m;
        cin >> m;
        vector<int> tile(m);
        for (auto &e : tile) {
            cin >> e;
        }
        int n, t;
        cin >> n >> t;

        vector dp(n + 1, vector(t + 1, 0ll));
        dp[0][0] = 1;
        for (const auto x : tile) {
            for (int k = n; k >= 1; k--) {
                for (int s = t; s >= x; s--) {
                    dp[k][s] += dp[k - 1][s - x];
                }
            }
        }

        const auto win = dp[n][t];
        const auto lose = cmb[m][n] - win;

        printf("Game %d -- %lld : %lld\n", game, win, lose);
    }
    return 0;
}

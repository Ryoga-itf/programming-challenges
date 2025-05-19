#include <iostream>
#include <vector>
using namespace std;

template <class T> inline bool chmin(T &a, T b) noexcept {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        vector<int> s(m);
        for (auto &e : s) {
            cin >> e;
        }
        constexpr auto INF = 1 << 29, H = 1001;
        vector dp(m + 1, vector(H, INF));
        vector prev_h(m + 1, vector(H, -1));
        vector act(m + 1, vector(H, '?'));
        dp[0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int h = 0; h < H; h++) {
                if (dp[i][h] == INF) {
                    continue;
                }
                if (const auto nxt = h + s[i], x = max(dp[i][h], nxt); nxt < H) {
                    if (chmin(dp[i + 1][nxt], x)) {
                        prev_h[i + 1][nxt] = h;
                        act[i + 1][nxt] = 'U';
                    }
                }
                if (const auto nxt = h - s[i], x = max(dp[i][h], nxt); nxt >= 0) {
                    if (chmin(dp[i + 1][nxt], x)) {
                        prev_h[i + 1][nxt] = h;
                        act[i + 1][nxt] = 'D';
                    }
                }
            }
        }
        if (dp[m][0] == INF) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            string ans;
            int cur_h = 0;
            for (int i = m; i >= 1; i--) {
                ans = act[i][cur_h] + ans;
                cur_h = prev_h[i][cur_h];
            }
            cout << ans << endl;
        }
    }
    return 0;
}

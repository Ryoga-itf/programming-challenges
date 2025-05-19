#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector dp(n, vector(n + 1, 1 << 29));
    dp[0][0] = 0;
    dp[1][1] = a[1];
    queue<pair<int, int>> que;
    que.emplace(1, 1);
    while (!que.empty()) {
        const auto [cur, jump] = que.front();
        que.pop();
        if (const auto nxt = cur + jump + 1; nxt < n) {
            if (chmin(dp[nxt][jump + 1], dp[cur][jump] + a[nxt])) {
                que.emplace(nxt, jump + 1);
            }
        }
        if (const auto nxt = cur - jump; nxt >= 0) {
            if (chmin(dp[nxt][jump], dp[cur][jump] + a[nxt])) {
                que.emplace(nxt, jump);
            }
        }
    }
    cout << ranges::min(dp[n - 1]) << endl;
    return 0;
}

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int h, n, m;
    cin >> h >> n >> m;
    vector s(n, vector(m, (char)0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
        }
    }
    constexpr int di[6] = {0, 0, -1, -1, 1, 1};
    constexpr int dj[2][6] = {
        {1, -1, -1, 0, -1, 0},
        {1, -1, 0, 1, 0, 1},
    };
    priority_queue<int> spaces;
    for (int si = 0; si < n; si++) {
        for (int sj = 0; sj < m; sj++) {
            if (s[si][sj] != '.') {
                continue;
            }
            int space = 1;
            queue<pair<int, int>> que;
            s[si][sj] = '!';
            que.emplace(si, sj);
            while (!que.empty()) {
                const auto [i, j] = que.front();
                que.pop();
                for (int d = 0; d < 6; d++) {
                    const auto ni = i + di[d];
                    const auto nj = j + dj[i % 2][d];
                    if (clamp(ni, 0, n - 1) == ni and clamp(nj, 0, m - 1) == nj) {
                        if (s[ni][nj] != '.') {
                            continue;
                        }
                        space++;
                        s[ni][nj] = '!';
                        que.emplace(ni, nj);
                    }
                }
            }
            spaces.push(space);
        }
    }
    int ans = 0;
    while (h > 0) {
        const auto cur = spaces.top();
        spaces.pop();
        h -= cur;
        ans++;
    }
    cout << ans << endl;
    return 0;
}

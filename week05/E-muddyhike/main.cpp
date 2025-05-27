#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector depth(r, vector(c, 0));
    vector cost(r, vector(c, 1 << 29));
    queue<pair<int, int>> que;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            auto &e = depth[i][j];
            cin >> e;
            if (j == 0) {
                cost[i][j] = e;
                que.emplace(i, 0);
            }
        }
    }
    int ans = 1 << 29;
    while (!que.empty()) {
        const auto [x, y] = que.front();
        que.pop();
        if (y == c - 1) {
            ans = min(ans, cost[x][y]);
        }
        constexpr int dx[] = {0, 1, 0, -1};
        constexpr int dy[] = {1, 0, -1, 0};
        for (int d = 0; d < 4; d++) {
            const auto nx = x + dx[d];
            const auto ny = y + dy[d];
            if (clamp(nx, 0, r - 1) == nx and clamp(ny, 0, c - 1) == ny) {
                if (const auto nxt = max(cost[x][y], depth[nx][ny]); nxt < cost[nx][ny]) {
                    cost[nx][ny] = nxt;
                    que.emplace(nx, ny);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

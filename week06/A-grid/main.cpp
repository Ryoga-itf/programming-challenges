#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &l : s) {
        cin >> l;
    }
    constexpr auto INF = 1 << 29;
    vector dist(n, vector(m, INF));
    queue<pair<int, int>> que;
    que.emplace(0, 0);
    dist[0][0] = 0;
    while (!que.empty()) {
        const auto [x, y] = que.front();
        const auto c = s[x][y] - '0';
        que.pop();
        constexpr int dx[] = {0, 1, 0, -1};
        constexpr int dy[] = {1, 0, -1, 0};
        for (int d = 0; d < 4; d++) {
            const auto nx = x + dx[d] * c;
            const auto ny = y + dy[d] * c;
            if (clamp(nx, 0, n - 1) == nx and clamp(ny, 0, m - 1) == ny) {
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    que.emplace(nx, ny);
                }
            }
        }
    }
    int ans = dist[n - 1][m - 1];
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}

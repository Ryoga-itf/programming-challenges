#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int h, w;
        cin >> h >> w;
        if (h + w == 0) {
            break;
        }
        vector<string> s(h);
        for (auto &l : s) {
            cin >> l;
        }
        queue<pair<int, int>> que;
        vector dist(h, vector(w, pair{1 << 29, -1}));
        for (int j = 0; j < w; j++) {
            que.emplace(0, j);
            dist[0][j] = {s[0][j] - '0', -1};
        }
        constexpr int dx[] = {0, 1, 1, -1, 1, -1, -1, 0};
        constexpr int dy[] = {1, 0, 1, 1, -1, -1, 0, -1};
        while (!que.empty()) {
            const auto [x, y] = que.front();
            que.pop();
            for (int d = 0; d < 8; d++) {
                const auto nx = x + dx[d];
                const auto ny = y + dy[d];
                if (clamp(nx, 0, h - 1) == nx and clamp(ny, 0, w - 1) == ny) {
                    const auto c = s[nx][ny] - '0';
                    if (dist[nx][ny].first > dist[x][y].first + c) {
                        dist[nx][ny] = {dist[x][y].first + c, 0b111 & ~d};
                        que.emplace(nx, ny);
                    }
                }
            }
        }
        int d = 1 << 29, cx = h - 1, cy = 0;
        for (int j = 0; j < w; j++) {
            if (d > dist[h - 1][j].first) {
                d = dist[h - 1][j].first;
                cy = j;
            }
        }
        s[cx][cy] = ' ';
        while (cx > 0) {
            const auto [_, d] = dist[cx][cy];
            cx += dx[d];
            cy += dy[d];
            s[cx][cy] = ' ';
        }
        for (const auto &l : s) {
            cout << l << endl;
        }
        cout << endl;
    }
    return 0;
}

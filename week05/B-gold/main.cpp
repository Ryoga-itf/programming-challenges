#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    constexpr int dx[] = {0, 1, 0, -1};
    constexpr int dy[] = {1, 0, -1, 0};

    int w, h, px = 0, py = 0;
    cin >> w >> h;
    vector<string> s(h);
    for (int y = 0; y < h; y++) {
        auto &l = s[y];
        cin >> l;
        for (int x = 0; x < w; x++) {
            if (l[x] == 'P') {
                px = x;
                py = y;
                l[x] = '!';
            }
        }
    }

    const auto isInner = [&](const int x, const int y) -> bool { return clamp(x, 0, w - 1) and clamp(y, 0, h - 1); };
    const auto nextToTrap = [&](const int x, const int y) -> bool {
        bool res = false;
        for (int d = 0; d < 4; d++) {
            const auto nx = x + dx[d];
            const auto ny = y + dy[d];
            if (isInner(nx, ny)) {
                res |= s[ny][nx] == 'T';
            }
        }
        return res;
    };

    int ans = 0;
    queue<pair<int, int>> que;
    que.emplace(px, py);
    while (!que.empty()) {
        const auto [x, y] = que.front();
        que.pop();
        if (nextToTrap(x, y)) {
            continue;
        }
        for (int d = 0; d < 4; d++) {
            const auto nx = x + dx[d];
            const auto ny = y + dy[d];
            if (isInner(nx, ny)) {
                auto &c = s[ny][nx];
                if (c == '#' or c == 'T' or c == '!') {
                    continue;
                }
                if (c == 'G') {
                    ans++;
                }
                que.emplace(nx, ny);
                c = '!';
            }
        }
    }
    cout << ans << endl;
    return 0;
}

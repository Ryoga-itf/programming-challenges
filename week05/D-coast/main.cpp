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
    vector<string> s(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = '0' + s[i] + '0';
    }
    s[0] = s[n + 1] = string(m + 2, '0');
    constexpr int dx[] = {0, 1, 0, -1};
    constexpr int dy[] = {1, 0, -1, 0};
    const auto inner = [&](int x, int y) -> bool { return clamp(x, 0, n + 1) == x and clamp(y, 0, m + 1) == y; };
    const auto countCoast = [&](int x, int y) -> int {
        int res = 0;
        for (int d = 0; d < 4; d++) {
            const auto nx = x + dx[d];
            const auto ny = y + dy[d];
            if (inner(nx, ny) and s[nx][ny] == '1') {
                res++;
            }
        }
        return res;
    };
    int ans = 0;
    queue<pair<int, int>> que;
    que.emplace(0, 0);
    while (!que.empty()) {
        const auto [x, y] = que.front();
        que.pop();
        for (int d = 0; d < 4; d++) {
            const auto nx = x + dx[d];
            const auto ny = y + dy[d];
            if (inner(nx, ny) and s[nx][ny] == '0') {
                ans += countCoast(nx, ny);
                s[nx][ny] = '!';
                que.emplace(nx, ny);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;
using ll = long long;

int main() {
    int n;
    string s;
    cin >> n >> s;
    const string T = "ICPCASIASG";
    queue<pair<int, size_t>> que;
    for (int i = 0; i < n * n; i++) {
        if (s[i] == T[0]) {
            que.emplace(i, 0);
        }
    }
    while (!que.empty()) {
        const auto [p, cur] = que.front();
        que.pop();
        if (cur >= T.size() - 1) {
            cout << "YES" << endl;
            return 0;
        }
        constexpr int dx[] = {1, 2, -1, -2, 1, 2, -1, -2};
        constexpr int dy[] = {2, 1, 2, 1, -2, -1, -2, -1};
        for (int d = 0; d < 8; d++) {
            const auto np = p + n * dx[d] + dy[d];
            if (clamp(np, 0, n * n - 1) == np) {
                if (s[np] == T[cur + 1]) {
                    que.emplace(np, cur + 1);
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}

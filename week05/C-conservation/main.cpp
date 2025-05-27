#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> labo(n);
        for (auto &e : labo) {
            cin >> e;
        }
        vector<int> deg(n);
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            g[--a].push_back(--b);
            deg[b]++;
        }
        int ans = 1 << 29;
        for (const auto s : {1, 2}) {
            auto d = deg;
            vector<int> dist(n, 1 << 29);
            deque<int> que;
            for (int i = 0; i < n; i++) {
                if (d[i] == 0) {
                    if (labo[i] == s) {
                        que.push_front(i);
                        dist[i] = 0;
                    } else {
                        que.push_back(i);
                        dist[i] = 1;
                    }
                }
            }
            while (!que.empty()) {
                const auto cur = que.front();
                que.pop_front();
                for (const auto to : g[cur]) {
                    if (--d[to] == 0) {
                        const auto diff = labo[cur] != labo[to];
                        if (const auto c = dist[cur] + diff; c < dist[to]) {
                            dist[to] = c;
                            if (diff) {
                                que.push_back(to);
                            } else {
                                que.push_front(to);
                            }
                        }
                    }
                }
            }
            ans = min(ans, ranges::max(dist));
        }
        cout << ans << endl;
    }
    return 0;
}

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    for (int n, m, a, k;;) {
        cin >> n >> m >> a >> k;
        if (n + m + a + k == 0) {
            break;
        }
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < m; i++) {
            int t1, t2, d;
            cin >> t1 >> t2 >> d;
            --t1, --t2;
            g[t1].emplace_back(t2, d);
            g[t2].emplace_back(t1, d);
        }
        int ans = n;
        vector<bool> status(n);
        vector<int> dist(n);
        for (int i = 0; i < a; i++) {
            int b;
            cin >> b;
            --b;
            using P = pair<int, int>;
            priority_queue<P, vector<P>, greater<P>> que;
            ranges::fill(dist, 1 << 29);
            que.emplace(0, b);
            dist[b] = 0;
            while (!que.empty()) {
                const auto [cost, cur] = que.top();
                que.pop();
                if (dist[cur] < cost) {
                    continue;
                }
                if (!status[cur]) {
                    status[cur] = true;
                    ans--;
                }
                for (const auto &[to, w] : g[cur]) {
                    if (const auto nxt = dist[cur] + w; dist[to] > nxt and nxt < k) {
                        dist[to] = nxt;
                        que.emplace(nxt, to);
                    }
                }
            }
            cout << ans << endl;
        }
        cout << endl;
    }
    return 0;
}


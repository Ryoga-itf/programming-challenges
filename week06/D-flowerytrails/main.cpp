#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int p, t;
    cin >> p >> t;
    vector<vector<pair<int, int>>> g(p);
    for (int i = 0; i < t; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    const auto dist = [&]() {
        vector<ll> dist(p, 1LL << 60);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
        dist[0] = 0;
        que.emplace(0, 0);
        while (!que.empty()) {
            const auto [cost, cur] = que.top();
            que.pop();
            if (dist[cur] < cost) {
                continue;
            }
            for (const auto &[to, w] : g[cur]) {
                if (dist[to] > dist[cur] + w) {
                    dist[to] = dist[cur] + w;
                    que.emplace(dist[to], to);
                }
            }
        }
        return dist;
    }();
    ll ans = 0;
    vector<bool> use(p);
    use[p - 1] = true;
    const auto rec = [&](auto self, int cur) -> bool {
        if (use[cur]) {
            return true;
        }
        for (const auto &[to, w] : g[cur]) {
            if (dist[to] == dist[cur] + w) {
                if (self(self, to)) {
                    use[cur] = true;
                    ans += w;
                }
            }
        }
        return use[cur];
    };
    rec(rec, 0);
    cout << 2 * ans << endl;
    return 0;
}

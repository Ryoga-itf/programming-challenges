#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<pair<int, ll>>> g(n);
    x += 100;
    while (m--) {
        int c1, c2, t;
        cin >> c1 >> c2 >> t;
        --c1, --c2;
        g[c1].emplace_back(c2, t);
        g[c2].emplace_back(c1, t);
    }
    constexpr ll inf = 1LL << 60;
    const auto dijkstraWithLimit = [&](const ll limit) {
        using P = pair<ll, int>;
        vector<ll> dist(n, inf);
        priority_queue<P, vector<P>, greater<P>> que;
        dist[0] = 0;
        que.emplace(0, 0);
        while (!que.empty()) {
            const auto [cost, cur] = que.top();
            que.pop();
            if (dist[cur] < cost) {
                continue;
            }
            for (const auto &[to, w] : g[cur]) {
                if (w > limit) {
                    continue;
                }
                if (const auto nxt = dist[cur] + w; dist[to] > nxt) {
                    dist[to] = nxt;
                    que.emplace(nxt, to);
                }
            }
        }
        return dist[n - 1];
    };
    const auto normal = dijkstraWithLimit(inf);
    ll left = 0, right = inf;
    while (abs(left - right) > 1) {
        const auto mid = (left + right) / 2;
        const auto dist = dijkstraWithLimit(mid);
        const auto ok = dist * 100 <= normal * x;

        (ok ? right : left) = mid;
    }
    cout << right << endl;
    return 0;
}

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    struct edge {
        int to;
        ll t0, p, d;
        edge(int to, ll t0, ll p, ll d) : to(to), t0(t0), p(p), d(d) {}
    };
    vector<vector<edge>> g(n);
    while (m--) {
        int u, v;
        ll t0, p, d;
        cin >> u >> v >> t0 >> p >> d;
        g[v].emplace_back(u, t0, p, d);
    }
    using P = pair<ll, int>;
    vector<ll> time(n, -1);
    priority_queue<P> que;
    time[n - 1] = s;
    que.emplace(s, n - 1);
    while (!que.empty()) {
        const auto [t, cur] = que.top();
        que.pop();
        if (time[cur] > t) {
            continue;
        }
        for (const auto &[to, t0, p, d] : g[cur]) {
            // cur -> to
            const auto start = t - d;
            // solve: t0 + p * x <= start (x >= 0)
            const auto x = (start - t0) / p;
            if (x < 0) {
                continue;
            }
            const auto nxt = t0 + p * x;
            if (time[to] < nxt) {
                time[to] = nxt;
                que.emplace(nxt, to);
            }
        }
    }
    if (time[0] == -1) {
        cout << "impossible" << endl;
    } else {
        cout << time[0] << endl;
    }
    return 0;
}

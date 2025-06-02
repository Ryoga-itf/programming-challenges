#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

struct MfGraph {
    using Cap = int;
    explicit MfGraph(int n) : n(n), g(n) {}

    int addEdge(int from, int to, Cap cap) {
        const int m = ssize(pos);
        pos.emplace_back(from, ssize(g[from]));
        const int from_id = ssize(g[from]);
        const int to_id = ssize(g[to]) + (from == to);
        g[from].emplace_back(to, to_id, cap);
        g[to].emplace_back(from, from_id, 0);
        return m;
    }

    Cap flow(int s, int t, Cap flow_limit) {
        vector<int> level(n), iter(n);
        queue<int> que;

        const auto bfs = [&]() {
            ranges::fill(level, -1);
            level[s] = 0;
            while (!que.empty()) {
                que.pop();
            }
            que.push(s);
            while (!que.empty()) {
                const auto cur = que.front();
                que.pop();
                for (const auto &to : g[cur]) {
                    if (to.cap == 0 or level[to.to] >= 0) {
                        continue;
                    }
                    level[to.to] = level[cur] + 1;
                    if (to.to == t) {
                        return;
                    }
                    que.push(to.to);
                }
            }
        };
        const auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) {
                return up;
            }
            Cap res = 0;
            const auto level_v = level[v];
            for (int &i = iter[v]; i < int(g[v].size()); i++) {
                const auto &e = g[v][i];
                if (level_v <= level[e.to] or g[e.to][e.rev].cap == 0) {
                    continue;
                }
                const auto d = self(self, e.to, min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) {
                    continue;
                }
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) {
                    return res;
                }
            }
            level[v] = n;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) {
                break;
            }
            ranges::fill(iter, 0);
            const auto f = dfs(dfs, t, flow_limit - flow);
            if (!f) {
                break;
            }
            flow += f;
        }
        return flow;
    }

  private:
    int n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    vector<pair<int, int>> pos;
    vector<vector<_edge>> g;
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) {
        cin >> c;
    }
    const auto s = ranges::max_element(a) - a.begin();
    const auto t = ranges::min_element(a) - a.begin();
    MfGraph g(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            const auto d = gcd(a[i], a[j]);
            if (d == 1) {
                continue;
            }
            g.addEdge(i, j, d);
            g.addEdge(j, i, d);
        }
    }
    const auto flow = g.flow(s, t, numeric_limits<int>::max());
    cout << flow << endl;
    return 0;
}

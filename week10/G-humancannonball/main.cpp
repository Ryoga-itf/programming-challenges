#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    const double speed = 5.0;
    const double canon_t = 2.0;
    const double canon_d = 50.0;
    double sx, sy, tx, ty;
    int n;
    cin >> sx >> sy >> tx >> ty >> n;
    vector<pair<double, double>> pos(n);
    for (auto &[x, y] : pos) {
        cin >> x >> y;
    }
    const int s = n, t = n + 1;
    n += 2;
    vector<vector<pair<int, double>>> g(n);
    pos.emplace_back(sx, sy), pos.emplace_back(tx, ty);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // i -> j
            const auto [xi, yi] = pos[i];
            const auto [xj, yj] = pos[j];
            const auto dist1 = hypot(xi - xj, yi - yj);

            g[i].emplace_back(j, dist1 / speed);
            g[j].emplace_back(i, dist1 / speed);

            const auto dist2 = abs(dist1 - canon_d);
            if (i < s) {
                g[i].emplace_back(j, canon_t + dist2 / speed);
            }
            if (j < s) {
                g[j].emplace_back(i, canon_t + dist2 / speed);
            }
        }
    }

    vector<double> time(n, numeric_limits<double>::infinity());
    using P = pair<double, int>;
    priority_queue<P, vector<P>, greater<P>> que;
    time[s] = 0.0;
    que.emplace(time[s], s);
    while (!que.empty()) {
        const auto [cost, cur] = que.top();
        que.pop();
        if (time[cur] < cost) {
            continue;
        }
        for (const auto &[to, w] : g[cur]) {
            if (const auto nxt = time[cur] + w; time[to] > nxt) {
                time[to] = nxt;
                que.emplace(nxt, to);
            }
        }
    }
    printf("%.10f\n", time[t]);
    return 0;
}

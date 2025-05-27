#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> par;
    UnionFind(const size_t n) : par(n, -1) {}
    int root(const size_t x) noexcept { return (par[x] < 0 ? x : par[x] = root(par[x])); }
    bool unite(size_t x, size_t y) noexcept {
        x = root(x);
        y = root(y);
        if (x == y) {
            return false;
        }
        if (par[x] > par[y]) {
            std::swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    inline bool same(const size_t x, const size_t y) noexcept { return root(x) == root(y); }
    inline int size(const size_t x) noexcept { return -par[root(x)]; };
};

int main() {
    constexpr int INF = 1 << 29;
    int n, m, p;
    cin >> n >> m >> p;
    vector<bool> insecure(n);
    for (int i = 0, v; i < p; i++) {
        cin >> v;
        insecure[--v] = true;
    }
    vector<tuple<int, int, int>> secure_edges;
    vector<int> left_edges(n, INF);
    int best_insecure_edge = INF;
    for (int i = 0, x, y, l; i < m; i++) {
        cin >> x >> y >> l;
        --x, --y;
        const auto ix = insecure[x], iy = insecure[y];
        if (!ix and !iy) {
            secure_edges.emplace_back(l, x, y);
        } else if (ix ^ iy) {
            const auto ins = ix ? x : y;
            left_edges[ins] = min(left_edges[ins], l);
        } else {
            best_insecure_edge = min(best_insecure_edge, l);
        }
    }
    if (n == p) {
        if (n == 1) {
            cout << 0 << endl;
        } else if (n == 2) {
            if (best_insecure_edge == INF) {
                cout << "impossible" << endl;
            } else {
                cout << best_insecure_edge << endl;
            }
        } else {
            cout << "impossible" << endl;
        }
        return 0;
    }
    ranges::sort(secure_edges);
    int cost = 0;
    UnionFind uf(n);
    int used = 0;
    for (const auto &[l, x, y] : secure_edges) {
        if (uf.unite(x, y)) {
            cost += l;
            used++;
        }
    }
    if (used != n - p - 1) {
        cout << "impossible" << endl;
        return 0;
    }
    for (int v = 0; v < n; v++) {
        if (insecure[v]) {
            if (left_edges[v] == INF) {
                cout << "impossible" << endl;
                return 0;
            }
            cost += left_edges[v];
        }
    }
    cout << cost << endl;
    return 0;
}

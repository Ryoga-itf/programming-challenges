#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> par;
    UnionFind(const int n) : par(n, -1) {}
    int root(const int x) noexcept { return (par[x] < 0 ? x : par[x] = root(par[x])); }
    bool unite(int x, int y) noexcept {
        x = root(x), y = root(y);
        if (x == y) {
            return false;
        }
        if (par[x] > par[y]) {
            swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(const int x, const int y) noexcept { return root(x) == root(y); }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int w, n;
        cin >> w >> n;
        vector<double> x(n), y(n), r(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> r[i];
        }
        const int L = n, R = n + 1;
        UnionFind uf(n + 2);
        vector<tuple<double, int, int>> ev;

        const auto add = [&](double t, int a, int b) {
            if (t <= 0) {
                uf.unite(a, b);
            } else {
                ev.emplace_back(t, a, b);
            }
        };

        for (int i = 0; i < n; i++) {
            add((x[i] - r[i] - 0) / 2.0, i, L);
            add((w - x[i] - r[i]) / 2.0, i, R);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dx = x[i] - x[j], dy = y[i] - y[j];
                double diff = hypot(dx, dy);
                add((diff - r[i] - r[j]) / 2.0, i, j);
            }
        }

        if (uf.same(L, R)) {
            cout << 0 << endl;
            continue;
        }

        ranges::sort(ev);
        double block = numeric_limits<double>::infinity();
        const double wd = w / 2.0;
        for (const auto &[t, a, b] : ev) {
            if (t > wd) {
                break;
            }
            uf.unite(a, b);
            if (uf.same(L, R)) {
                block = t;
                break;
            }
        }
        printf("%.10f\n", isinf(block) ? wd : min(block, wd));
    }
    return 0;
}

#include <iostream>
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
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        uf.unite(--a, --b);
    }
    if (uf.size(0) == n) {
        cout << "Connected" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (!uf.same(0, i)) {
                cout << i + 1 << endl;
            }
        }
    }
    return 0;
}

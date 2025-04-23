#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

struct AlmostUnionFind {
    vector<set<ll>> entries;
    vector<ll> sums, indexes;

    AlmostUnionFind(const int n) : entries(n), sums(n), indexes(n) {
        for (int i = 0; i < n; i++) {
            entries[i].insert(i);
            sums[i] = i + 1;
            indexes[i] = i;
        }
    }
    inline bool unite(int x, int y) noexcept {
        x = indexes[x];
        y = indexes[y];
        if (x == y) {
            return false;
        }
        if (entries[x].size() < entries[y].size()) {
            swap(x, y);
        }
        // rx <- ry
        for (const auto &e : entries[y]) {
            entries[x].insert(e);
            indexes[e] = x;
        }
        sums[x] += sums[y];
        return true;
    }
    inline bool move(ll x, ll y) noexcept {
        const auto rx = indexes[x];
        const auto ry = indexes[y];
        if (rx == ry) {
            return false;
        }
        entries[rx].erase(x);
        entries[ry].insert(x);
        sums[rx] -= x + 1;
        sums[ry] += x + 1;
        indexes[x] = ry;
        return true;
    }
    inline pair<ll, ll> size_and_sum(int x) noexcept {
        x = indexes[x];
        return {entries[x].size(), sums[x]};
    }
};

int main() {
    for (int n, m; ~scanf("%d %d", &n, &m);) {
        AlmostUnionFind uf(n);
        while (m--) {
            int t;
            cin >> t;
            ll p, q;
            array<function<void()>, 3>{
                [&]() {
                    cin >> p >> q;
                    uf.unite(--p, --q);
                },
                [&]() {
                    cin >> p >> q;
                    uf.move(--p, --q);
                },
                [&]() {
                    cin >> p;
                    const auto [sz, sum] = uf.size_and_sum(--p);
                    cout << sz << ' ' << sum << endl;
                },
            }[t - 1]();
        }
    }
    return 0;
}

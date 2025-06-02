#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    for (int c;;) {
        cin >> c;
        if (c == 0) {
            break;
        }
        map<string, int> s;
        for (int i = 0; i < c; i++) {
            string t;
            cin >> t;
            s[t] = i;
        }
        int r;
        cin >> r;
        vector<tuple<int, int, double>> edges(r);
        for (auto &e : edges) {
            string p, q;
            cin >> p >> q;
            int a, b;
            scanf("%d:%d", &a, &b);
            const auto w = -log(static_cast<double>(b) / a);
            e = {s[p], s[q], w};
        }

        vector<double> dist(c, 0.0);
        for (int i = 0; i < c - 1; i++) {
            bool ok = false;
            for (const auto &[u, v, w] : edges) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    ok = true;
                }
            }
            if (!ok) {
                break;
            }
        }

        bool neg = false;
        for (const auto &[u, v, w] : edges) {
            if (dist[u] + w < dist[v]) {
                neg = true;
                break;
            }
        }
        cout << (neg ? "Arbitrage" : "Ok") << endl;
    }
    return 0;
}

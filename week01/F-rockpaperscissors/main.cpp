#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    for (int p = 0;; p++) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        } else if (p > 0) {
            puts("");
        }
        int k;
        cin >> k;
        vector<pair<int, int>> wl(n);
        for (int i = 0; i < k * n * (n - 1) / 2; i++) {
            int p1, p2;
            string m1, m2;
            cin >> p1 >> m1 >> p2 >> m2;
            const auto rps = [](string s, string t) -> int {
                if (s == "rock") {
                    return (t == "rock" ? 0 : t == "paper" ? -1 : 1);
                } else if (s == "paper") {
                    return (t == "rock" ? 1 : t == "paper" ? 0 : -1);
                } else {
                    return (t == "rock" ? -1 : t == "paper" ? 1 : 0);
                }
            }(m1, m2);
            if (rps == 1) {
                wl[p1 - 1].first++;
                wl[p2 - 1].second++;
            } else if (rps == -1) {
                wl[p1 - 1].second++;
                wl[p2 - 1].first++;
            }
        }
        for (const auto &[w, l] : wl) {
            if (w + l == 0) {
                printf("-\n");
            } else {
                printf("%.3f\n", static_cast<double>(w) / static_cast<double>(w + l));
            }
        }
    }
    return 0;
}

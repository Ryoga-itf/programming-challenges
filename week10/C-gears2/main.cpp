#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> gears(n), turns(n);
    for (auto &[x, y, r] : gears) {
        cin >> x >> y >> r;
    }
    queue<int> que;
    que.push(0);
    turns[0] = {1, 1, 1}; // +1/1
    while (!que.empty()) {
        const auto i = que.front();
        que.pop();
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            const auto [xi, yi, ri] = gears[i];
            const auto [xj, yj, rj] = gears[j];
            const auto dist = (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj);
            const auto connected = dist == (ri + rj) * (ri + rj);
            if (connected) {
                // i -> j
                const auto [si, pi, qi] = turns[i];
                const auto [sj, pj, qj] = turns[j];
                const auto sn = -si;
                const auto pn = pi * rj;
                const auto qn = qi * ri;
                const auto d = gcd(pn, qn);

                if (sj == 0) {
                    turns[j] = {sn, pn / d, qn / d};
                    que.push(j);
                } else {
                    if (sj != sn or pj != pn / d or qj != qn / d) {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    const auto [s, p, q] = turns[n - 1];
    if (s == 0) {
        cout << 0 << endl;
    } else {
        cout << p << ' ' << s * q << endl;
    }
    return 0;
}

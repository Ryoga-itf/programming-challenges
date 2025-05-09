#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m + k);
    for (auto &&e : a) {
        cin >> e;
        e *= 2 * e;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b[i] *= 2 * b[i];
    }
    for (int i = m; i < m + k; i++) {
        cin >> b[i];
        b[i] *= b[i];
    }
    ranges::sort(a);
    ranges::sort(b);
    size_t idx = 0;
    int ans = 0;
    for (const auto &e : a) {
        if (idx >= b.size()) {
            break;
        }
        if (e > b[idx]) {
            idx++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

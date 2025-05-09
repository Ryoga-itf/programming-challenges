#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ul(n);
    for (auto &&[u, l] : ul) {
        cin >> l >> u;
        ++u;
    }
    int ans = 0, last = 0;
    ranges::sort(ul);
    for (const auto &[u, l] : ul) {
        if (l < last) {
            continue;
        }
        ans++;
        last = u;
    }
    cout << ans << endl;
    return 0;
}

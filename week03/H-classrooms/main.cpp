#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> fs(n);
    for (auto &&[f, s] : fs) {
        cin >> s >> f;
    }
    ranges::sort(fs);
    multiset<int> now;
    for (int i = 0; i < k; i++) {
        now.insert(0);
    }
    int ans = 0;
    for (const auto &[f, s] : fs) {
        const auto it = now.lower_bound(s);
        if (it != now.begin()) {
            now.erase(prev(it));
            now.insert(f);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

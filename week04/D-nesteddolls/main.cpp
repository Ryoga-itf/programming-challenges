#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<pair<int, int>> wh(m);
        for (auto &[w, h] : wh) {
            cin >> w >> h;
        }
        ranges::sort(wh, [](auto a, auto b) { return a.first != b.first ? a.first < b.first : a.second > b.second; });
        vector<int> dp;
        for (const auto &[w, h] : wh) {
            const auto it = upper_bound(dp.begin(), dp.end(), -h);
            if (it == dp.end()) {
                dp.push_back(-h);
            } else {
                *it = -h;
            }
        }
        cout << dp.size() << endl;
    }
    return 0;
}

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
using ll = long long;

int main() {
    while (true) {
        string tmp, s;
        getline(cin, tmp);
        if (tmp.empty()) {
            break;
        }
        s.reserve(tmp.size());
        for (const auto &c : tmp) {
            if (c != ' ') {
                s.push_back(c);
            }
        }
        const int n = s.size();
        for (int l = 1; l <= n; l++) {
            unordered_map<string, int> count;
            count.reserve(n - l + 1);
            for (int i = 0; i + l <= n; i++) {
                count[s.substr(i, l)]++;
            }
            int ans = 0;
            for (const auto &[x, y] : count) {
                ans = max(ans, y);
            }

            if (ans < 2) {
                cout << endl;
                break;
            }

            cout << ans << endl;
        }
    }
    return 0;
}

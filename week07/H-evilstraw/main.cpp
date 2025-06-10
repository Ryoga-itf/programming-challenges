#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    const auto solve = [](string &s) -> void {
        int ans = 0;
        while (s.size() > 1) {
            const int n = s.size();
            const auto f = s.front();
            const auto b = s.back();
            if (f != b) {
                int costf = 1 << 29, costb = 1 << 29;
                int fi = -1, bi = -1;
                for (int i = n - 1; i >= 1; i--) {
                    if (s[i] == f) {
                        fi = i;
                        costf = n - 1 - i;
                        break;
                    }
                }
                for (int i = 0; i < n - 1; i++) {
                    if (s[i] == b) {
                        bi = i;
                        costb = i;
                        break;
                    }
                }
                if (fi == -1 and bi == -1) {
                    cout << "Impossible" << endl;
                    return;
                }
                if (costf <= costb) {
                    const string t = s.substr(1, fi - 1) + s.substr(fi + 1);
                    s = t;
                    ans += costf;
                } else {
                    const string t = s.substr(0, bi) + s.substr(bi + 1, n - bi - 2);
                    s = t;
                    ans += costb;
                }
            } else {
                s = s.substr(1, n - 2);
            }
        }
        cout << ans << endl;
    };
    while (n--) {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}

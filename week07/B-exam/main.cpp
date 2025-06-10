#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main() {
    int k;
    string s, t;
    cin >> k >> s >> t;
    int ans = 0;
    const auto n = s.size();
    for (size_t i = 0; i < n and k > 0; i++) {
        if (s[i] == t[i]) {
            s[i] = t[i] = 'x';
            ans++;
            k--;
        }
    }
    for (size_t i = 0; i < n; i++) {
        if (s[i] == 'x') {
            continue;
        }
        if (k == 0) {
            if (s[i] != t[i]) {
                ans++;
            }
        } else {
            k--;
        }
    }
    cout << ans << endl;
    return 0;
}

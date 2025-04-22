#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    const auto simulate = [&](char t) -> int {
        const auto n = s.size();
        char cur = s[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != cur) {
                ans++;
            }
            if (t) {
                if (s[i] != t) {
                    ans++;
                }
                cur = t;
            } else {
                cur = s[i];
            }
        }
        return ans;
    };
    cout << simulate('U') << endl;
    cout << simulate('D') << endl;
    cout << simulate(0) << endl;
    return 0;
}

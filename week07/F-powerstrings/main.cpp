#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    const auto prefix = [](const string &s) -> vector<int> {
        int m = s.size();
        vector<int> pi(m, 0);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 and s[i] != s[j]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
                pi[i] = j;
            }
        }
        return pi;
    };
    while (true) {
        string s;
        cin >> s;
        if (s == ".") {
            break;
        }
        const int n = s.size();
        const auto pi = prefix(s);
        const auto p = n - pi[n - 1];
        if (p < n and n % p == 0) {
            cout << n / p << endl;
        } else {
            cout << 1 << endl;
        }
    }
    return 0;
}

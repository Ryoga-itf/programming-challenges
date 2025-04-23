#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main() {
    string s, t;
    cin >> s >> t;
    const int n = static_cast<int>(t.size());
    if (s.size() >= n) {
        const auto m = s.size() - n + 1;
        cout << s.substr(0, m);
        string p = s.substr(m);
        int len = 0;
        for (int i = p.size() - 1; i >= 0; i--) {
            if (p[i] == '0') {
                len++;
            } else {
                break;
            }
        }
        if (p.size() > len) {
            cout << '.' << p.substr(0, p.size() - len) << endl;
        } else {
            cout << endl;
        }
    } else {
        const auto m = n - s.size() - 1;
        cout << "0." << string(m, '0');
        int len = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                len++;
            } else {
                break;
            }
        }
        cout << s.substr(0, s.size() - len) << endl;
    }
    return 0;
}


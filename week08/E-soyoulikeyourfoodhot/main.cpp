#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main() {
    const auto input = []() -> ll {
        string s;
        cin >> s;
        size_t dot = s.find('.');
        ll dollars = 0, cents = 0;
        if (dot == string::npos) {
            dollars = stoll(s);
        } else {
            dollars = stoll(s.substr(0, dot));
            auto frac = s.substr(dot + 1);
            if (frac.size() == 0) {
                frac = "00";
            } else if (frac.size() == 1) {
                frac += '0';
            } else {
                frac = frac.substr(0, 2);
            }
            cents = stoll(frac);
        }
        return dollars * 100 + cents;
    };
    const auto pt = input();
    const auto p1 = input();
    const auto p2 = input();
    bool none = true;
    for (ll n1 = 0; n1 * p1 <= pt; n1++) {
        const ll rem = pt - n1 * p1;
        if (rem % p2 == 0) {
            const ll n2 = rem / p2;
            cout << n1 << ' ' << n2 << endl;
            none = false;
        }
    }
    if (none) {
        cout << "none" << endl;
    }
    return 0;
}

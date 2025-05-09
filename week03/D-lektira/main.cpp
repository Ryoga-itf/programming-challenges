#include <iostream>
#include <set>
#include <string>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    const auto n = s.size();
    set<string> p;
    for (size_t i = 1; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            string t = string(s.rbegin() + j, s.rend()) + string(s.rbegin() + i, s.rbegin() + j) + string(s.rbegin(), s.rbegin() + i);
            p.insert(t);
        }
    }
    cout << *p.begin() << endl;
    return 0;
}

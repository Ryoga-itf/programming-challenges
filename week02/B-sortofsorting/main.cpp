#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<string> s(n);
        for (auto &e : s) {
            cin >> e;
        }
        ranges::stable_sort(s, [](string a, string b) { return a.substr(0, 2) < b.substr(0, 2); });
        for (const auto &e : s) {
            cout << e << endl;
        }
        cout << endl;
    }
    return 0;
}


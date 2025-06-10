#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int k, w;
        cin >> k >> w;
        string s;
        cin >> s;
        while (--w) {
            string t;
            cin >> t;
            for (int i = k; i >= 0; i--) {
                const auto p = s.substr(s.size() - i);
                if (t.starts_with(p)) {
                    s += t.substr(p.size());
                    break;
                }
            }
        }
        cout << s.size() << endl;
    }
    return 0;
}

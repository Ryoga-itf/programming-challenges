#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    for (int n, m; t--;) {
        cin >> n >> m;
        ll ans = 1;
        for (ll i = 0; i < n - m + 1; i++) {
            ans *= n - i;
            ans /= i + 1;
        }
        cout << ans << endl;
    }
    return 0;
}

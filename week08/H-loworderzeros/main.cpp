#include <iostream>
using namespace std;
using ll = long long;

int main() {
    for (ll i;;) {
        cin >> i;
        if (i == 0) {
            break;
        }
        int right0 = 0;
        for (ll p = 5; p <= i; p *= 5) {
            right0 += i / p;
        }
        int ans = 1;
        for (ll p = 1; p <= i; p++) {
            ll t = p;
            while (t % 5 == 0) {
                t /= 5;
            }
            while (t % 2 == 0 and right0-- > 0) {
                t /= 2;
            }
            ans = (ans * t) % 10;
        }
        cout << ans << endl;
    }
    return 0;
}

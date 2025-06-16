#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll p = 1, q = 1, t;
    cin >> n >> t;
    for (ll s; --n;) {
        cin >> s;
        const auto np = p * t, nq = q * s;
        const auto d = gcd(np, nq);
        p = np / d, q = nq / d;
        cout << p << '/' << q << endl;
        t = s;
    }
    return 0;
}

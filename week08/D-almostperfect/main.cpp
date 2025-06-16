#include <cstdlib>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    for (ll n; ~scanf("%lld", &n);) {
        ll sum = -n;
        for (ll i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                const auto p = n / i;
                sum += i + (p != i ? p : 0);
            }
        }
        const auto diff = abs(n - sum);
        cout << n << (diff == 0 ? " " : (diff <= 2 ? " almost " : " not ")) << "perfect" << endl;
    }
    return 0;
}

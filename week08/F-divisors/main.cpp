#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    constexpr ll MAX_N = 501;
    auto prime = []() {
        vector<bool> v(MAX_N, true);
        v[0] = v[1] = false;
        for (ll p = 2; p * p < MAX_N; p++) {
            if (v[p]) {
                for (ll i = p + p; i < MAX_N; i += p) {
                    v[i] = false;
                }
            }
        }
        return v;
    }();
    for (ll n, k; ~scanf("%lld %lld", &n, &k);) {
        vector<ll> den(k + 1), num(k);
        const ll offset = n - k + 1;
        for (ll i = 1; i <= k; i++) {
            den[i] = i;
        }
        for (ll i = 0; i < k; i++) {
            num[i] = offset + i;
        }
        ll ans = 1;
        for (ll p = 2; p < MAX_N; p++) {
            if (prime[p]) {
                int power = 0;
                for (ll i = p; i <= k; i += p) {
                    while (den[i] % p == 0) {
                        power--;
                        den[i] /= p;
                    }
                }
                for (ll i = (offset + p - 1) / p * p; i <= n; i += p) {
                    while (num[i - offset] % p == 0) {
                        power++;
                        num[i - offset] /= p;
                    }
                }
                ans *= power + 1;
            }
        }
        for (ll i = offset; i <= n; i++) {
            if (num[i - offset] != 1) {
                ans *= 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

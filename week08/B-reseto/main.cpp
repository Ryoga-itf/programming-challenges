#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 0; p <= n; p++) {
        if (!prime[p]) {
            continue;
        }
        for (int q = p; q <= n; q += p) {
            if (prime[q]) {
                if (!--k) {
                    cout << q << endl;
                    return 0;
                }
            }
            prime[q] = false;
        }
    }
    return 0;
}

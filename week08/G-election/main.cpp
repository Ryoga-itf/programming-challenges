#include <iostream>
using namespace std;
using ll = long long;

int main() {
    const auto pow2 = [](int n) -> double {
        static double tbl[51] = {1.0};
        static bool init = false;
        if (!init) {
            for (int i = 1; i <= 50; i++) {
                tbl[i] = tbl[i - 1] * 2.0;
            }
            init = true;
        }
        return tbl[n];
    };
    const auto binom = [](int n, int k) -> ll {
        if (k < 0 or k > n) {
            return 0;
        }
        static ll c[51][51] = {};
        static bool built = false;
        if (!built) {
            for (int i = 0; i <= 50; i++) {
                c[i][0] = c[i][i] = 1;
                for (int j = 1; j < i; j++) {
                    c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                }
            }
            built = true;
        }
        return c[n][k];
    };
    int t;
    cin >> t;
    while (t--) {
        int n, v1, v2, w;
        cin >> n >> v1 >> v2 >> w;
        const auto res = [&]() {
            const int m = v1 + v2;
            const int r = n - m;
            const double threshold = w / 100.0;
            if (v1 * 2 > n) {
                return 0;
            }
            const int need = (n / 2 + 1) - v1;
            double p = 0.0;
            if (need <= r) {
                const double den = pow2(r);
                for (int k = need; k <= r; k++) {
                    p += binom(r, k) / den;
                }
            }
            return (p > threshold + 1e-12 ? 0 : (p < 1e-12 ? 1 : 2));
        }();
        if (res == 0) {
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
        } else if (res == 1) {

            cout << "RECOUNT!" << endl;
        } else {

            cout << "PATIENCE, EVERYONE!" << endl;
        }
    }
    return 0;
}

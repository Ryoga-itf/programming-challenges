#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<int> t(n), p(n);
        for (int i = 0; i < n; i++) {
            double tmp;
            cin >> t[i] >> tmp;
            p[i] = static_cast<int>(tmp * 100);
        }
        int best_profit = numeric_limits<int>::min();
        int best_len = numeric_limits<int>::max();
        int best_s = -1, best_g = -1;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += p[j];
                int len = t[j] - t[i] + 1;
                int profit = sum - 8 * len;

                if (profit > best_profit || (profit == best_profit && (len < best_len || (len == best_len && t[i] < best_s)))) {
                    best_profit = profit;
                    best_len = len;
                    best_s = t[i];
                    best_g = t[j];
                }
            }
        }
        if (best_profit <= 0) {
            cout << "no profit" << endl;
        } else {
            const auto d = best_profit / 100;
            const auto c = best_profit % 100;
            cout << d << '.' << setw(2) << setfill('0') << c << ' ' << best_s << ' ' << best_g << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> inc(n);
    for (int i = n - 1; i >= 0; i--) {
        inc[i] = 0;
        for (int j = i + 1; j < n; j++) {
            if (w[j] > w[i]) {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> tails;
        tails.reserve(n);
        for (int k = 0; k < n; k++) {
            if (w[k] < w[i]) {
                const auto x = -w[k];
                const auto it = lower_bound(tails.begin(), tails.end(), x);
                if (it == tails.end()) {
                    tails.push_back(x);
                } else {
                    *it = x;
                }
            }
        }
        const auto f = 1 + inc[i];
        const auto r = static_cast<int>(tails.size());
        ans = max(ans, f + r);
    }

    cout << ans << endl;
    return 0;
}

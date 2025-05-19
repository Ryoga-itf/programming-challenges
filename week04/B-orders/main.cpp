#include <iostream>
#include <vector>
using namespace std;

int main() {
    enum class state {
        Impossible,
        Ambiguous,
        Explicit,
    };
    constexpr auto M_MAX = 30000;
    int n;
    cin >> n;
    vector<int> c(n);
    vector<state> dp(M_MAX + 1, state::Impossible);
    dp[0] = state::Explicit;
    for (auto &k : c) {
        cin >> k;
        for (int i = 0; i <= M_MAX; i++) {
            if (dp[i] != state::Impossible) {
                if (i + k <= M_MAX) {
                    if (dp[i + k] != state::Impossible) {
                        dp[i + k] = state::Ambiguous;
                    } else {
                        dp[i + k] = dp[i];
                    }
                }
            }
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        if (dp[t] == state::Impossible) {
            cout << "Impossible" << endl;
        } else if (dp[t] == state::Ambiguous) {
            cout << "Ambiguous" << endl;
        } else {
            int i = t;
            for (int j = 0; j < n; j++) {
                const auto k = c[j];
                while (i > 0) {
                    if (const auto nxt = i - k; nxt >= 0 and dp[nxt] == state::Explicit) {
                        i = nxt;
                        cout << j + 1 << ' ';
                    } else {
                        break;
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}

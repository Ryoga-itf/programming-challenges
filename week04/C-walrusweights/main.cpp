#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> dp(2002, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        auto d = dp;
        for (int j = 0; j < 2002; j++) {
            if (dp[j]) {
                d[j] = true;
                if (j + t < 2002) {
                    d[j + t] = true;
                }
            }
        }
        swap(dp, d);
    }
    for (int i = 0; i < 1000; i++) {
        if (dp[1000 + i]) {
            cout << 1000 + i << endl;
            break;
        }
        if (dp[1000 - i]) {
            cout << 1000 - i << endl;
            break;
        }
    }
    return 0;
}

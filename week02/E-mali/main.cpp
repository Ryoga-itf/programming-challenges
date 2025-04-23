#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(101), b(101);
    for (int i = 1; i <= n; i++) {
        int p, q;
        cin >> p >> q;
        a[p]++;
        b[q]++;
        int left = 1, right = 100;
        auto s = a, t = b;
        int ans = 0, count = 0;
        while (count != i) {
            if (s[left] == 0) {
                left++;
                continue;
            }
            if (t[right] == 0) {
                right--;
                continue;
            }
            if (s[left] >= t[right]) {
                s[left] -= t[right];
                count += t[right];
                t[right] = 0;
            } else {
                t[right] -= s[left];
                count += s[left];
                s[left] = 0;
            }
            ans = max(ans, left + right);
        }
        cout << ans << endl;
    }
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> bot(h + 1), top(h + 1);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        (i % 2 == 0 ? bot[p] : top[p])++;
    }
    for (int i = h - 1; i >= 0; i--) {
        bot[i] += bot[i + 1];
        top[i] += top[i + 1];
    }
    int ans = 1 << 29, num = 0;
    for (int i = 1; i <= h; i++) {
        const auto cur = bot[i] + top[h - i + 1];
        if (cur < ans) {
            ans = cur;
            num = 1;
        } else if (cur == ans) {
            num++;
        }
    }
    cout << ans << ' ' << num << endl;
    return 0;
}

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int ts = 1;
    int n;
    while (~scanf("%d", &n)) {
        vector<int> a(n);
        for (auto &&e : a) {
            cin >> e;
        }
        ranges::sort(a);
        int m;
        cin >> m;
        printf("Case %d:\n", ts++);
        while (m--) {
            int p;
            cin >> p;
            int ans = 0, diff = 1 << 29;
            for (const auto &e : a) {
                const auto target = p - e;
                const auto it = lower_bound(a.begin(), a.end(), target);
                if (it != a.end() and *it != e) {
                    if (const auto sum = *it + e; diff > abs(p - sum)) {
                        diff = abs(p - sum);
                        ans = sum;
                    }
                }
                if (it != a.begin() and *prev(it) != e) {
                    if (const auto sum = *prev(it) + e; diff > abs(p - sum)) {
                        diff = abs(p - sum);
                        ans = sum;
                    }
                }
            }
            printf("Closest sum to %d is %d.\n", p, ans);
        }
    }
    return 0;
}

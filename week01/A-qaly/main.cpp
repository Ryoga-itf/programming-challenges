#include <cstdio>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        double q, y;
        cin >> q >> y;
        ans += q * y;
    }
    printf("%.10f\n", ans);
    return 0;
}

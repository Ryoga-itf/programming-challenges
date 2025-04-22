#include <cstdio>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    int d = 1;
    if (m > n) {
        swap(n, m);
        d = -1;
    }
    const int a = n - m;
    const int b = 360 - n + m;
    const auto tmp = d * (a < b ? -a : b);
    cout << (abs(tmp) == 180 ? 180 : tmp) << endl;
    return 0;
}

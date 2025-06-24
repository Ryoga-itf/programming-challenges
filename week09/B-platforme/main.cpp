#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <array>
#include <cstdlib>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    array<array<char, 10005>, 10005> cell;
    while (n--) {
        int y, x1, x2;
        cin >> y >> x1 >> x2;
        cell[y][x1] = cell[y][x2 - 1] = 1;
        for (int x = x1 + 1; x < x2 - 1; x++) {
            cell[y][x] = 2;
        }
    }
    int ans = 0;
    for (int x = 0; x <= 10000; x++) {
        bool f = false;
        for (int y = 10000; y >= 1; y--) {
            if (cell[y][x] == 1) {
                f = true;
            }
            if (f) {
                if (cell[y][x] == 2) {
                    f = false;
                } else {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

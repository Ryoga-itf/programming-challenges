#include <cstdlib>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m, bx, by, px, py;
        cin >> m >> bx >> by >> px >> py;
        m -= 2;
        int ans = 0;
        while (m--) {
            int x, y;
            cin >> x >> y;
            const int x1 = px - bx, y1 = py - by;
            const int x2 = x - bx, y2 = y - by;
            ans += abs(x1 * y2 - x2 * y1);
            px = x, py = y;
        }
        cout << ans / 2;
        if (ans % 2 == 1) {
            cout << ".5";
        }
        cout << endl;
    }
    return 0;
}

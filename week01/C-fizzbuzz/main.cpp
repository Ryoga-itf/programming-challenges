#include <cstdio>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int x, y, n;
    cin >> x >> y >> n;
    for (int i = 1; i <= n; i++) {
        bool f = false;
        if (i % x == 0) {
            cout << "Fizz";
            f = true;
        }
        if (i % y == 0) {
            cout << "Buzz";
            f = true;
        }
        if (!f) {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}

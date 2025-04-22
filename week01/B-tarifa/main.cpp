#include <cstdio>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int x, n;
    cin >> x >> n;
    int cur = x;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (cur < p) {
            cur = 0;
        } else {
            cur -= p;
        }
        cur += x;
    }
    cout << cur << endl;
    return 0;
}

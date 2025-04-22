#include <cstdio>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    if (n <= 3) {
        cout << 1 << endl;
    } else {
        cout << n - 3 + 1 << endl;
    }
    return 0;
}

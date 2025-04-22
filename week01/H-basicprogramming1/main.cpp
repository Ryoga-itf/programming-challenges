#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (auto &&e : a) {
        cin >> e;
    }
    switch (t) {
    case 1:
        cout << 7;
        break;
    case 2:
        cout << (a[0] > a[1] ? "Bigger" : a[0] < a[1] ? "Smaller" : "Equal");
        break;
    case 3:
        sort(a.begin(), a.begin() + 3);
        cout << a[1];
        break;
    case 4:
        cout << accumulate(a.begin(), a.end(), 0ll);
        break;
    case 5:
        cout << accumulate(a.begin(), a.end(), 0ll, [](ll acc, ll i) { return acc + (i % 2 == 0 ? i : 0); });
        break;
    case 6:
        for (auto &e : a) {
            e %= 26;
            cout << char(e + 'a');
        }
        break;
    case 7:
        vector<bool> visited(n);
        for (int i = 0;; i = a[i]) {
            if (i >= n) {
                cout << "Out";
                break;
            } else if (i == n - 1) {
                cout << "Done";
                break;
            }
            if (visited[i]) {
                cout << "Cyclic";
                break;
            }
            visited[i] = true;
        }
        break;
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int m;
    cin >> m;
    vector<int> s, num(m + 1);
    for (int i = 1; i * i * i <= m; i++) {
        s.push_back(i * i * i);
    }
    const int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            const auto t = s[i] + s[j];
            if (t <= m) {
                num[t]++;
            }
        }
    }
    for (int i = m; i >= 0; i--) {
        if (num[i] >= 2) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "none" << endl;
    return 0;
}

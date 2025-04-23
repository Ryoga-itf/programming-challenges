#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector p(n, vector(m, 0ll));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> p[i][j];
        }
    }
    vector<int> ans(n), wait(m);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            ans[i] = max(ans[i], wait[j]) + p[i][j];
            wait[j] = ans[i];
        }
    }
    for (const auto &e : ans) {
        cout << e << ' ';
    }
    cout << endl;
    return 0;
}


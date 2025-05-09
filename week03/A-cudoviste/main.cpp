#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int r, c;
    cin >> r >> c;
    vector<string> s(r);
    for (auto &&line : s) {
        cin >> line;
    }
    vector<int> ans(5);
    for (int i = 0; i < r - 1; i++) {
        for (int j = 0; j < c - 1; j++) {
            int status = 0;
            for (int di = 0; di < 2; di++) {
                for (int dj = 0; dj < 2; dj++) {
                    const auto c = s[i + di][j + dj];
                    if (c == '#') {
                        status = -114514;
                    } else if (c == 'X') {
                        status++;
                    }
                }
            }
            if (status >= 0) {
                ans[status]++;
            }
        }
    }
    for (const auto &e : ans) {
        cout << e << endl;
    }
    return 0;
}

#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int p, t;
    cin >> p >> t;
    int i, j;
    vector<string> op(p, string(t, '.'));
    while (~scanf("%d %d", &i, &j)) {
        op[i - 1][j - 1] = '*';
    }
    set<string> s;
    for (const auto &e : op) {
        s.insert(e);
    }
    cout << s.size() << endl;
    return 0;
}


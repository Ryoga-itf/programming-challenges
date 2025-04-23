#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> arrows(1000003);
    while (n--) {
        int h;
        cin >> h;
        if (arrows[h] == 0) {
            ans++;
            arrows[h - 1]++;
        } else {
            arrows[h]--;
            arrows[h - 1]++;
        }
    }
    cout << ans << endl;
}


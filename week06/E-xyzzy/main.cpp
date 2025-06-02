#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    for (int n;;) {
        cin >> n;
        if (n == -1) {
            break;
        }
        vector<int> energy(n);
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            int d;
            cin >> energy[i] >> d;
            g[i].reserve(d);
            while (d--) {
                int v;
                cin >> v;
                g[i].push_back(--v);
            }
        }
        vector<int> best(n, -1 << 29);
        best[0] = 100;
        for (int i = 0; i < n - 1; i++) {
            bool ok = false;
            for (int cur = 0; cur < n; cur++) {
                if (best[cur] <= 0) {
                    continue;
                }
                for (const auto &to : g[cur]) {
                    if (const auto nxt = best[cur] + energy[to]; nxt > 0 and nxt > best[to]) {
                        best[to] = nxt;
                        ok = true;
                    }
                }
            }
            if (!ok) {
                break;
            }
        }
        bool ans = (best[n - 1] > 0);
        if (!ans) {
            vector<bool> visited(n);
            queue<int> que;
            for (int cur = 0; cur < n; cur++) {
                if (best[cur] <= 0) {
                    continue;
                }
                for (const auto &to : g[cur]) {
                    if (const auto nxt = best[cur] + energy[to]; nxt > 0 and nxt > best[to]) {
                        que.push(to);
                        visited[to] = true;
                    }
                }
            }
            while (!que.empty() and !ans) {
                const auto cur = que.front();
                que.pop();
                if (cur == n - 1) {
                    ans = true;
                }
                for (const auto &to : g[cur]) {
                    if (!visited[to]) {
                        visited[to] = true;
                        que.push(to);
                    }
                }
            }
        }
        cout << (ans ? "winnable" : "hopeless") << endl;
    }
    return 0;
}

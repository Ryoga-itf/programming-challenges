#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<char> colour(n, -1);
    int c = 0, p = 0;
    queue<int> que;
    for (int s = 0; s < n; s++) {
        if (colour[s] != -1) {
            continue;
        }
        c++;
        colour[s] = 0;
        que.push(s);
        bool bipartite = true;
        while (!que.empty()) {
            const auto cur = que.front();
            que.pop();
            for (const auto to : g[cur]) {
                if (colour[to] == -1) {
                    colour[to] = colour[cur] ^ 1;
                    que.push(to);
                } else if (colour[to] == colour[cur]) {
                    bipartite = false; // odd cycle
                }
            }
        }
        if (!bipartite) {
            p++;
        }
    }
    cout << c - (p > 0) << endl;
    return 0;
}

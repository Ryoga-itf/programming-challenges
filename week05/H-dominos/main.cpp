#include <iostream>
#include <vector>
using namespace std;

struct StronglyConnectedComponents {
  public:
    using graph_type = vector<vector<int>>;

    StronglyConnectedComponents() = default;
    explicit StronglyConnectedComponents(const size_t n) : m_size(n), m_graph(n), m_revGraph(n) {}
    explicit StronglyConnectedComponents(const graph_type &g) : m_size(g.size()), m_graph(g), m_revGraph(g.size()) {
        for (int i = 0; i < m_size; i++) {
            for (const auto to : g[i]) {
                m_revGraph[to].push_back(i);
            }
        }
    }
    constexpr bool isEmpty() const noexcept { return (m_size == 0); }
    constexpr size_t size() const noexcept { return m_size; }
    void addEdge(const size_t from, const size_t to) {
        m_graph[from].push_back(to);
        m_revGraph[to].push_back(from);
    }
    pair<graph_type, vector<vector<size_t>>> build() const {
        vector<bool> visited(m_size);
        vector<size_t> order, group(m_size);
        vector<vector<size_t>> groupList;
        auto dfs = [&](auto self, const size_t v) -> void {
            visited[v] = true;
            for (auto to : m_graph[v]) {
                if (!visited[to]) {
                    self(self, to);
                }
            }
            order.push_back(v);
        };
        auto rdfs = [&](auto self, const size_t v, int k) -> void {
            visited[v] = true;
            group[v] = k;
            groupList.back().push_back(v);
            for (auto to : m_revGraph[v]) {
                if (!visited[to]) {
                    self(self, to, k);
                }
            }
        };
        for (int i = 0; i < m_size; i++) {
            if (!visited[i]) {
                dfs(dfs, i);
            }
        }
        visited.assign(m_size, false);
        int groups = 0;
        for (int i = m_size - 1; i >= 0; i--) {
            if (!visited[order[i]]) {
                groupList.push_back({});
                rdfs(rdfs, order[i], groups++);
            }
        }
        graph_type compressedGraph(groups);
        for (int i = 0; i < m_size; i++) {
            for (auto e : m_graph[i]) {
                compressedGraph[group[i]].push_back(group[e]);
            }
        }
        return {compressedGraph, groupList};
    }

  private:
    size_t m_size = 0;
    graph_type m_graph, m_revGraph;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        StronglyConnectedComponents scc(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            scc.addEdge(--x, --y);
        }
        const auto [sg, ids] = scc.build();
        vector<int> deg(sg.size());
        for (int from = 0; from < sg.size(); from++) {
            for (const auto to : sg[from]) {
                if (from != to) {
                    deg[to]++;
                }
            }
        }
        int ans = 0;
        for (const auto v : deg) {
            if (v == 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

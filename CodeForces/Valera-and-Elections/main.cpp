#include <bits/stdc++.h>
using namespace std;

set<int> required_nodes;

bool dfs(vector<vector<pair<int, bool>>> &graph, int fixed_total, int fixed_since_last_split, int last_node, int u, int parent) {
    if (u != 0 && graph[u].size() == 1) {
        if (fixed_since_last_split > fixed_total) {
            required_nodes.emplace(u);
            return true;
        }
        return false;
    }
    
    if (graph[u].size() > 2 && fixed_since_last_split > fixed_total) {
        last_node = u;
        fixed_total = fixed_since_last_split;
    }

    bool fixed = false;
    for (pair<int, bool> &v : graph[u]) {
        if (v.first != parent) {
            if (v.second) {
                fixed = true;
                dfs(graph, fixed_total, fixed_since_last_split + 1, last_node, v.first, u);
            }
            else 
                if (dfs(graph, fixed_total, fixed_since_last_split, last_node, v.first, u))
                    fixed = true;
        }
    }

    if (!fixed && fixed_since_last_split > 0) 
        required_nodes.emplace(u);
    return true;    
}

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int, bool>>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y, b;
        cin >> x >> y >> b;
        x--; y--;

        graph[x].push_back({y, (b == 2)});
        graph[y].push_back({x, (b == 2)});
    }
    
    dfs(graph, 0, 0, -1, 0, -1);

    cout << required_nodes.size() << endl;
    for (int v : required_nodes)
        cout << v + 1 << " ";
}

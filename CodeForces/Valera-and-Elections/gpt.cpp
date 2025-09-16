#include <bits/stdc++.h>
using namespace std;

set<int> required_nodes;

void dfs(vector<vector<pair<int,bool>>> &graph, int u, int parent, int bad_from_parent) {
    // bad_from_parent == 1 if the edge (parent -> u) is a problem road

    bool need = bad_from_parent; // mark this node if its incoming edge was problem
    
    for (auto &v : graph[u]) {
        if (v.first == parent) continue;
        dfs(graph, v.first, u, v.second);
        if (v.second) need = false; // child already marked, so this node isn't required
    }

    if (need) required_nodes.insert(u);
}

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int,bool>>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y, b;
        cin >> x >> y >> b;
        x--; y--;
        graph[x].push_back({y, b == 2});
        graph[y].push_back({x, b == 2});
    }

    dfs(graph, 0, -1, 0);

    cout << required_nodes.size() << "\n";
    for (int v : required_nodes)
        cout << v + 1 << " ";
    cout << "\n";
}


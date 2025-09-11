#include <bits/stdc++.h>
using namespace std;

vector<map<int, set<pair<int, int>>>> required_nodes;

void dfs(vector<vector<pair<int, bool>>> &graph, pair<int, int> fixed, int u) {
    if (graph[u].size() == 0) {
        if (fixed) 
            required_nodes.push_back(u);
        return;
    }
    
    for (pair<int, bool> &v : graph[u]) {
        if (v.second) {
            v.second = false;
            dfs(graph, true, v.first);
        } 
        else 
            dfs(graph, fixed, v.first);
    }
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
    }
    
    dfs(graph, false, 0);

    cout << required_nodes.size() << endl;
    for (int v : required_nodes)
        cout << v + 1 << " ";
}

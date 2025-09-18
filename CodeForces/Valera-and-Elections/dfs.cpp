#include <bits/stdc++.h>
using namespace std;

vector<int> final_nodes;
vector<vector<pair<int, int>>> sets;

void dfs(vector<vector<pair<int, bool>>> &graph, set<pair<int, int>> &fixed_nodes, int u, int parent) {
    if (u != 0 && graph[u].size() == 1) {
        if (fixed_nodes.size() != 0) {
            final_nodes.push_back(u);
            sets.push_back(vector<pair<int,int>>(fixed_nodes.begin(), fixed_nodes.end()));
        }
        return;
    }
    
    for (pair<int, bool> &v : graph[u]) {
        if (v.first != parent) {
            if (v.second) {
                fixed_nodes.insert({u, v.first});
                dfs(graph, fixed_nodes, v.first, u);
                fixed_nodes.erase({u, v.first});
            }
            else
                dfs(graph, fixed_nodes, v.first, u);
        }
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
        graph[y].push_back({x, (b == 2)});
    }
    
    set<pair<int, int>> fx;
    dfs(graph, fx, 0, -1);

    vector<bool> to_remove(sets.size(), false);
    for (int i = 0; i < sets.size(); i++) {
        for (int j = 0; j < sets.size(); j++) {
            if (i == j) continue;

            if (includes(sets[i].begin(), sets[i].end(), sets[j].begin(), sets[j].end()))
                to_remove[j] = true;
        }
    }

    vector<int> ans;
    for (int i = 0; i < sets.size() ; i++) {
        if (!to_remove[i])
            ans.push_back(final_nodes[i]);
    }

    cout << ans.size() << endl;
    for (int e : ans)
        cout << e + 1 << " ";
}

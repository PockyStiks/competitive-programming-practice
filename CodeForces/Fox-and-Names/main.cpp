#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> names;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        names.push_back(name);
    }
    
    vector<vector<int>> graph(26);
    vector<int> in_degree(26, 0);
    for (int i = 0; i < n-1; i++) {
        if (names[i+1].size() < names[i].size() && names[i].substr(0, names[i+1].size()) == names[i+1]) {
            cout << "Impossible";
            return 0;
        }

        for (int c = 0; c < min(names[i].size(), names[i+1].size()); c++) {
            if (names[i][c] == names[i+1][c]) 
                continue;

            graph[names[i][c] - 'a'].push_back(names[i+1][c] - 'a');
            in_degree[names[i+1][c] - 'a']++;
            break;
        }
    }

    queue<int> q;
    vector<int> topo;    
    for (int i = 0; i < 26; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        topo.push_back(u);
        q.pop();

        for (int v : graph[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0)
                q.push(v);
        }
    }

    if (topo.size() != 26) {
        cout << "Impossible";
        return 0;
    }

    for (int e : topo)
        cout << (char)('a' + e);
}
    

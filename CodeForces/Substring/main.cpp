#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    string l;
    cin >> n >> m >> l;

    vector<vector<int>> adj(n + 1, vector<int>(0));
    vector<int> in_degree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in_degree[y]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) 
        if (in_degree[i] == 0)    
            q.push(i);

    vector<int> topo;
    while(!q.empty()) {
        int x = q.front();
        topo.push_back(x);
        q.pop();

        for (int v : adj[x]) {
            in_degree[v]--;
            if (in_degree[v] == 0)
                q.push(v);
        }
    }

    if ((int)topo.size() != n) {
        cout << -1;
        return 0;
    }
    
    vector<char> letters(n + 1);
    for (int i = 1; i <= n; i++) 
        letters[i] = l[i - 1];

    vector<vector<int>> dp(n + 1, vector<int>(26, 0));
    for (int i : topo)
        dp[i][letters[i] - 'a']++;
    
    for (int i : topo)
        for (int j : adj[i])
            for (int c = 0; c < 26; c++)
                dp[j][c] = max(dp[j][c], dp[i][c] + ((letters[j] - 'a') == c));

    int ans = 0;
    for (int i : topo)
        for (int c : dp[i])
            ans = max(ans, c);
    cout << ans;
}

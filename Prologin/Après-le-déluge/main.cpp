#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> coords(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coords[i] = pair<int, int>(x, y);
    }

    vector<vector<double>> m(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[i][j] = sqrt(pow(abs(coords[i].first - coords[j].first), 2) + pow(abs(coords[i].second - coords[j].second), 2));

    double inf = numeric_limits<double>::max();
    vector<double> key(n, inf);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (int v = 0; v < n; v++) {
            if (!inMST[v] && m[u][v] < key[v]) {
                key[v] = m[u][v];
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    double ans = 0;
    for (int i = 1; i < n; i++) 
        ans += m[i][parent[i]];
    cout << floor(ans);
}

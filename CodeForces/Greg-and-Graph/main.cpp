#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin >> n;
    vector<vector<long long>> dist(n, vector<long long>(n, -1));
    vector<int> to_add;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            cin >> x;
            dist[i][j] = x; 
        }

   for (int i = 0; i < n; i++) {
        cin >> x;
        x--;
        to_add.push_back(x);
    }
    reverse(to_add.begin(), to_add.end());

    if (n == 1) {
        cout << 0;
        return 0;
    }

    vector<bool> added(n, false);
    vector<long long> ans;

    for (int step = 0; step < n; step++) {
        int k = to_add[step];
        added[k] = true;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) 
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        long long total = 0;
        for (int i = 0; i < n; i++)
            if (added[i])
                for (int j = 0; j < n; j++) 
                    if (added[j])
                        total += dist[i][j];
        ans.push_back(total);
    }

    reverse(ans.begin(), ans.end());
    for (long long e : ans)
        cout << e << " ";
}

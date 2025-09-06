#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin >> n;
    vector<vector<long long>> m(n, vector<long long>(n, -1));
    vector<long long> to_remove;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            cin >> x;
            m[i][j] = x; 
        }
    }
    for (long long i = 0; i < n; i++) {
        cin >> x;
        to_remove.push_back(x);
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }

    for (long long step = -1; step < n; step++) {
        if (step > -1) {
            m.erase(m.begin() + (to_remove[step] - 1));
            for (vector<long long> &v : m) 
                v.erase(v.begin() + (to_remove[step] - 1));
        }

        vector<vector<long long>> dist = m;
        for (long long k = 0; k < dist.size(); k++)
            for (long long i = 0; i < dist.size(); i++)
                for (long long j = 0; j < dist.size(); j++) 
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        long long total = 0;
        for (vector<long long> &v : dist)
            total += accumulate(v.begin(), v.end(), 0LL);
        cout << total << " ";
        if (m.size() == 1) {
            // cout << 0;
            return 0;
        }
    }
}

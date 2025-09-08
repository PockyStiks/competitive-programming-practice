#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n, x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1 >> n;
    
    unordered_map<size_t, vector<pair<size_t, size_t>>> allowed_squares;
    for (int i = 0; i < n; i++) {
        size_t r, a, b;
        cin >> r >> a >> b;

        if (!allowed_squares.count(r))
            allowed_squares[r] = {};

        allowed_squares[r].push_back({a, b});
    }

    queue<pair<size_t, size_t>> q;
    map<pair<size_t, size_t>, size_t> dist;
    dist[pair<size_t, size_t>(x0, y0)] = 0;

    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    q.push(pair<size_t, size_t>(x0, y0));
    while (!q.empty()) {
        pair<size_t, size_t> u = q.front();
        q.pop();

        if (u.first == x1 && u.second == y1) {
            cout << dist[u];
            return 0;
        }

        for (int i = 0; i < 8; i++) {
            pair<size_t, size_t> p(u.first + dx[i], u.second + dy[i]);
            if (allowed_squares.count(p.first)) {
                for (int j = 0; j < allowed_squares[p.first].size(); j++) {
                    if (p.second >= allowed_squares[p.first][j].first && p.second <= allowed_squares[p.first][j].second && !dist.count(p)) {
                        q.push(p);
                        dist[p] = dist[u] + 1;
                    }
                }
            }
        }
    }
    cout << -1;
}

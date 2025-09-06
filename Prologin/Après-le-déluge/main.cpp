#include <bits/stdc++.h>
#include <system_error>
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

    
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            p[j] = x;
        }

        for (int j = 0; j < n; j++) {
            int days = 1;
            int owner = p[j];
            while (owner != j+1) {
                owner = p[owner - 1];
                days++;
            }
            cout << days << " ";
        }
        cout << endl;
    }
}

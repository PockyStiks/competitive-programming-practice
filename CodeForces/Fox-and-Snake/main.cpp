#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;    

    bool right = true;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int c = 0; c < m; c++) {
                cout << "#";
            }
            cout << endl;
        }
        else {
            if (right) {
                for (int c = 0; c < m-1; c++) {
                    cout << ".";
                }
                cout << "#" << endl;
            }
            else {
                cout << "#";
                for (int c = 0; c < m-1; c++) {
                    cout << ".";
                }
                cout << endl;
            }
            right = !right;
        }
    }
}

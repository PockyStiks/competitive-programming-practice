#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, l, r;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> l >> r;
        
        int n = to_string(l).size();
        if (l == r) {
            cout << n * 2 << endl;
            continue;
        }

        string str_l = to_string(l);
        string str_r = to_string(r); 

        int diff_pos = 0;
        for (int j = 0; j < n; j++) {
            if (to_string(l)[diff_pos] != to_string(r)[diff_pos])
                break;
            diff_pos++;
        }

        int ans = 0;
        int diff = abs(str_l[diff_pos] - str_r[diff_pos]);
        if (diff == 1) 
            ans += 2;
    }
}


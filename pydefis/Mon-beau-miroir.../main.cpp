#include <bits/stdc++.h>
using namespace std;

vector<int> nums = {396, 294, 290, 861, 481, 194, 570, 463, 265, 935};

int main() {
    for (int n : nums) {
        for (int i = 0; i < 10000; i++) {
            string s = to_string(n);
            string r = s;
            reverse(r.begin(), r.end()); 
            if (s == r) {
                cout << "[" << n << ", " << i << "], ";
                break;
            }
            n = stoi(s) + stoi(r);
        }
    }
    cout << endl;
}
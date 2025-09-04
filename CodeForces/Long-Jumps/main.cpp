#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, x;
        cin >> a;
        vector<int> nums = {};
        for (int j = 0; j < a; j++) {
            cin >> x;
            nums.push_back(x);
        }

        int ans = 0;
        for (int j = 0; j < a; j++) {
            int index = j + 1;
            int total = 0;
            while (index <= a) {
                int tmp = index;
                index += nums[index - 1];
                total += index - tmp;
            }
            
            ans = max(ans, total);
        }

        cout << ans << endl;
    }
}
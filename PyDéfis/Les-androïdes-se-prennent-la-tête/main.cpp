#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int p = 3; p < (67 * 67 * 67); p++) {
        for (int n = 3; n < min(p, 199); n++) {
            set<vector<int>> triplets = {};
            for (int i = 1; i < n; i++) {
                for (int j = i; i + j < n; j++) {
                    int k = n - (i + j);
                    if (i * j * k == p) {
                        vector<int> nums = {i, j, k};
                        sort(nums.begin(), nums.end());
                        triplets.insert(nums);
                    }
                }
             }   
            if (triplets.size() == 4) {
                cout << n << ", " << p << endl;
            }
        }
    }
}

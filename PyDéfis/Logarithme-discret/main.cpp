#include <bits/stdc++.h>
using namespace std;

int main() {
vector<int> nums = {50, 36, 153, 128, 71, 23, 75, 55, 208, 121};
    
    for (int b : nums) {
        int x = 0;
        while (static_cast<int>(pow(3, x)) % 223 != b) {
            x++;
        }
        cout << x << ", ";
    }
}

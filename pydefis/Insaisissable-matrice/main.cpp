#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> m = {{17, 3, 4, 14, 5, 17}, {8, 16, 3, 17, 14, 12}, {13, 5, 15, 4, 16, 3}, {14, 7, 3, 16, 3, 2}, {6, 1, 16, 10, 5, 13}, {11, 1, 9, 11, 18, 8}};
    for (int i = 0; i < 39; i++) 
        for (int j = 0; j < 6; j++)
            for (int k = 0; k < 6; k++)
                m[j][k] = ((m[j][k] * 9) + 3) % 19;

    int total = 0;
    for (auto i : m)
        for (int j : i)
            total += j;
            
    cout << total << endl;
}   
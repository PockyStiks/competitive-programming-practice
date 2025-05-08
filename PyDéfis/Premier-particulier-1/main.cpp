#include <bits/stdc++.h>
using namespace std;

int main() {
    int k = 53;
    int n = 0;
    while (true) {
        int m = (n * 34) + 35;
        bool premier = true;
        if (m % 2 != 0) {

            for (int i = 3; i <= sqrt(m); i += 2) {
                if (m % i == 0) {
                    premier = false;
                    break;
                }
            }
        }
        if (premier)
            k--;
        if (k == 0) {
            cout << m << ", " << n << endl;
            return 0;
        }
        n++;
    }
}
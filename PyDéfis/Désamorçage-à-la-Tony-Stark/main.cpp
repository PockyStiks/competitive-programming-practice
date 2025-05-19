#include <iostream>
using namespace std;

int main() {
    int n = 1435;
    int ans = 0;
    int i = 3;
    while (true) {
        if (i >= n) {
            cout << ans;
            return 0;
        }
        if (i % 3 == 0 || i % 5 == 0) 
            ans += i;

        i++;
    }
}

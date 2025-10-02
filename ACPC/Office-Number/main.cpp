#include <bits/stdc++.h>
using namespace std;

int ans = 0;

long long ipow(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++)
        result *= base;
    return result;
}

void backtracking(int &n, vector<int> &bases, vector<int> &exp, vector<int> &biggest, long long &total) {
    if (total == n) {
        for (auto e : exp)
            cout << e << " ";
        cout << endl;            
        ans++;
        return;
    }
    if (total > n)
        return;

    for (int i = 0; i < bases.size(); i++) {
        if (exp[i] < biggest[i]) {
            exp[i]++;
            total += (ipow(bases[i], exp[i]) - ipow(bases[i], exp[i] - 1));
            
            backtracking(n, bases, exp, biggest, total);

            total -= (ipow(bases[i], exp[i]) - ipow(bases[i], exp[i] - 1));
            exp[i]--;
        }
    }
}

int main() {
    int n;
    cin >> n; 

    string s = to_string(n);
    vector<int> bases;
    for (char c : s)
        bases.push_back(c  - '0');

    vector<int> biggest(bases.size(), 0);
    vector<int> exp(bases.size(), 0);
    for (int i = 0; i < bases.size(); i++) {
        while (pow(bases[i], biggest[i]) <= n) 
            biggest[i]++;
    }

    long long start_total = bases.size();
    backtracking(n, bases, exp, biggest, start_total); 
    cout << ans << endl;
}

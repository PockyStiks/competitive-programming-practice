#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s)) {
        for (int i = 1; i <= 26; i++) {
            for (int j = 0; j < s.size(); j++)
                s[j] = 'A' + (s[j] - 'A' + 1) % 26;

            if (s.find("SECRET") != string::npos && s.find("TROUVER") != string::npos) {
                cout << s << endl;
                break;
            }
        }
    }
}

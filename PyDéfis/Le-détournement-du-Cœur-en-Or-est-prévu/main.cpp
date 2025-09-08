#include <bits/stdc++.h>
using namespace std;

int main() {
    string message = "";
    string s = "";

    while (cin >> s) message.append(s);

    string key = "AAAAAAA" + message;
    key = key.substr(0, message.size());

    string ans2 = message;
    for (int i = 7; i < message.size(); i++)
        ans2[i] = ((((ans2[i] - 'A') - (key[i] - 'A')) + 'A') % 26) + 'A';

    cout << ans2;

    int i = 0;
    while (false) {
        for (int j = 0; j < message.size(); j++) {
        }

        if (key[i] == 'Z') {
            key[i] = 'A';
            i++;
            if (i > 7) {
                cout << "reached the end" << endl;
                return 0;
            }
        }
        key[i]++;
    }
}

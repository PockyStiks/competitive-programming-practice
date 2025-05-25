
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> m(3, string(7, '0'));
    char c;
    for (int i = 0; i < 7; i++) 
        for (int j = 0; j < 3; j++) {
            cin >> c;
            m[j][i] = c;
        }

    for (string l : m)
        cout << l << endl;    
    cout << endl;

    string command;
    int x, y;
    vector<tuple<string, int, int>> commands;

    while(cin >> command >> x >> y) {
        x--;
        y--;
        commands.push_back({command, x ,y});

    }

    reverse(commands.begin(), commands.end());

    for (auto com : commands) {
        string command = get<0>(com);
        int x = get<1>(com);
        int y = get<2>(com);
        cout << command << " " << x << " " << y << endl;


        if (command == "PC") {
            for (int i = 0; i < 3; i++) {
                swap(m[i][x], m[i][y]);
            }
        }

        else if (command == "PL") {
            swap(m[x], m[y]);
        }

        else if (command == "RC") {
            vector<char> chars(3, '0');
            for (int i = 0; i < 3; i++) 
                chars[i] = m[i][x];

            for (int i = 0; i < 3; i++)
                m[i][x] = chars[(i - (y) + 3) % 3];
        }

        else if (command == "RL") {
            string chars = m[x];
            for (int i = 0; i < 7; i++) 
                m[x][i] = chars[(i - (y) + 7) % 7];
        }

        for (string l : m)
        cout << l << endl;    
        cout << endl;
    }
}

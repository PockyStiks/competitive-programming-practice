#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, vector<string>> connections;
    unordered_set<string> macs;
    unordered_map<string, int> freq;
    string s;

    while (getline(cin, s)) {
        string mac = s.substr(19, 17);
        string name = s.substr(52, s.size() - 53);        

        if (connections.find(name) == connections.end())
            connections[name] = {};
        
        connections[name].push_back(mac);
        macs.emplace(mac);
    }

    for (string m1 : macs) {
        int biggest = 0;
        int x = 0;
        for (string m2 : macs) {
            x = 0;
            for (auto conn : connections) {
                if (m1 != m2 && find(conn.second.begin(), conn.second.end(), m1) != conn.second.end() && find(conn.second.begin(), conn.second.end(), m2) != conn.second.end()) {
                    x++;
                }
            }
            biggest = max(biggest, x);
        }
        cout << m1 << ", " << biggest << endl;
    }
}

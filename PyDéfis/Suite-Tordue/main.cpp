#include <bits/stdc++.h>
using namespace std;

int main() {
	int u = 2893;
	for (int i = 2; i <= 144; i++) {
		string s = to_string(u);
		while (s.size() < 4)
			s = '0' + s;
		int x = stoi(s.substr(0, 2)) + stoi(s.substr(2));
		x *= 140;
		x += 154;
		x %= 9973;
		u = x;
	}
	cout << u << endl;
}

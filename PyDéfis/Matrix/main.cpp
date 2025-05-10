#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> art;
	string s;
	while (getline(cin, s)) {
		cout << s << endl;
		art.push_back(s);
	}

   	int ans = 0;
   	for (int i = 0; i < art.size(); i++) {
   		for (int j = 0; j < art[i].size(); j++) {
   			if (art[i][j] != ' ')
   				ans += art[i][j] * (i + 1) * (j + 1); 
   		}
   	}
   	cout << ans << endl;
}
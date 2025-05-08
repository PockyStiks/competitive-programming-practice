#include<bits/stdc++.h>
using namespace std;

int n = 0;
int total = 0;
string s = "";
int main() {
	for (int i = 1; i <= 10000; i++) {
		s += to_string(i);

		if (s.size() >= 493)
			break;
	}

	for (int i = 424; i <= 493; i++) 
		total += s[i - 1] - '0';
	
	cout << total << endl;
}
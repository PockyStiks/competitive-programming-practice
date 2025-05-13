#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long u = 53;
	int n = 21;
	for (int i = 0; i < n; i++) {
		bitset<128> b1(u);
		string s = b1.to_string();
		int first = s.find('1');
		s = s.substr(first);

		int counter = 0;
		for (char c : s) 
			if (c == '1')
				counter++;

		bitset<128> b2(counter);
		string s2 = b2.to_string();
		first = s2.find('1');
		s2 = s2.substr(first);

		s = s + s2;
		u = stoull(s, nullptr, 2);
	} 
	cout << u << endl;
}
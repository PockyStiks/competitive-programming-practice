#include <bits/stdc++.h>
using namespace std;

int main() {
	string s(10000, '0');
	for (int n = 0; n < 2091; n++) {
		s[2 * n] = s[n];
		s[(2 * n) + 1] = '1' - (s[n] - '0');
	}
	string b = s.substr(2065, 27);
	std::bitset<27> bits(b);
	unsigned long ans = bits.to_ulong();
	cout << ans << endl;
}
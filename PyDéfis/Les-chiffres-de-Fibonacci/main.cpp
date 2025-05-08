#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map <int, int> mem = {{0, 0}, {1, 1}};
	for (int i = 2; i <= 100000; i++) {
		cout << i << " ";
		unsigned long long n = mem[i - 2] + mem[i - 1];
		mem[i] = n;
		// cout << mem[i] << " ";
		string s = to_string(n);
		int t = 0;
		for (char c : s)
			t += c - '0';
		if (t == 61) {
			cout << n << endl;
			return 0;
		}
	}
}
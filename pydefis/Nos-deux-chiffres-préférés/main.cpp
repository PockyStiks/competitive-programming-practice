#include <bits/stdc++.h>
using namespace std;

int main() {
	int total = 0;
	for (int n = 143; n <= 941; n++) {
		string s = to_string(n);
		if (find(s.begin(), s.end(), '1') != s.end() || find(s.begin(), s.end(), '6') != s.end())
			total += n;
	}
	cout << total << endl;
}
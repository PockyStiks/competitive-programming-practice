#include <bits/stdc++.h>
using namespace std;

int main() {
	string s(1349, 'x');
	string a = "010";
	string b = "010";

	int n = 0;
	while (n <= 20) {
		n++;
		if (a.size() > b.size()) 
			b = a;
		if (b.size() > a.size()) 
			a = b;

		for (int i = 1; i <= b.size(); i++) {
			s[(i * 3) - 1] = b[i - 1];
			if (s[i - 1] == 'x')
				s[i - 1] = b[i - 1];
		}
		for (int i = 1; i <= a.size(); i++) {
			s[i + (i / 3)] = a[i - 1];
			if (s[i - 1] == 'x')
				s[i - 1] = a[i - 1];
		}
	}
	cout << s << endl;
}

// 010001010010000101000011010000001110010000000001110101010000000000001011
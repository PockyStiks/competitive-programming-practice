#include <bits/stdc++.h>
using namespace std;

int main() {
	int a = 1;
	int b = 4;
	int c = 3;
	int k = 1;
	int n = 0;

	while (k < (1000 - n)) {
		a = b;
		b = c + a;
		c = -4 * c - 3 * a - b;
		n = a + b;
		k++; 
	}
	
	cout << a << ", " << b << ", " << c << endl;
}

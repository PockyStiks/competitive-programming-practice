#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 3188;
	vector<int> ans = {0, n};
	for (int a = 0; a <= (n / 13) + 1; a++) {
		int b = n - a * 13;
		if (b % 7 != 0)
			continue;
		b /= 7;
		if (abs(ans[0] - ans[1]) > abs(a - b)) {
			ans = {a, b};
		}
	}
	cout << ans[0] << ", " << ans[1] << endl;
}
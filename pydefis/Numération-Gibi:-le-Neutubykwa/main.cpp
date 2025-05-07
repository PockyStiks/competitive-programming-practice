#include <bits/stdc++.h>
using namespace std;

int main () {
	vector<int> nums = {207, 333, 204, 351, 112, 241, 236, 111, 312, 191};
	unordered_map<int, string> m = {{0, "KWA"}, {1, "BY"}, {2, "TU"}, {3, "NEU"}};
	for (int n : nums) {
		string ans = "";
		while (n != 0) {
			int x = n % 4;
			ans = m[x] + ans;
			n /= 4;
		}
		cout << '"' << ans << '"' << ", ";
	}
}
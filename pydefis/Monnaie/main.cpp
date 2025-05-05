#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> nums = {47, 13, 19, 62, 84, 32, 50, 42, 91, 93, 34, 19, 92, 35, 19, 4, 17};
	vector<int> coins = {50, 20, 10, 5, 2, 1};
	vector<int> ans(6, 0);
		
	for (int n : nums) {
		int i = 0;
		while (true) {
			if (n == 0)
				break;
			if (coins[i] <= n) {
				n -= coins[i];
				ans[i]++;
			}
			else
				i++;	
		}
	}
	for (int i : ans)
		cout << i << ", ";
	cout << endl;	
}	
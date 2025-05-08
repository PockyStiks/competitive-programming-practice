#include <bits/stdc++.h>
using namespace std;

vector<int> nums = {32, 37, 41, 42, 45, 49, 50, 51, 17, 54, 55, 28, 62};
set<vector<int>> ans;  

void findAns(vector<int> &sel, int pos) {
	int sum = accumulate(sel.begin(), sel.end(), 0);
	if (sel.size() > 1 && sum <= 249) {
		vector<int> tmp = sel;
		sort(tmp.begin(), tmp.end());
		ans.insert(tmp);
	}
		
	if (pos < nums.size()) {
		sel.push_back(nums[pos]);
		findAns(sel, pos + 1);
		sel.pop_back();
		findAns(sel, pos + 1);
	}
}

int main() {
	vector<int> sel;
	findAns(sel, 0);
	cout << ans.size() << endl;
}
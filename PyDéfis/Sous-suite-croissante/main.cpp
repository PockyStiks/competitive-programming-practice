#include <bits/stdc++.h>
using namespace std;

vector<int> nums = {-34, -16, 14, 1, -10, -29, 19, 16, -15, -19, -7, -26, -36, 14, -32, -18, -16, 18, -18, 30, 23, -12, 8, -18, -28, 18, -29, 5, 21, 28, 19, -26, -21, 37, 16, -29, 36, -10, 37, -4, -33, -18, -7, -20, -28, 35, -3, -15, -23, -40, 33, 0, 17, 39, -16, -7, 25, -32, 16, 3, -9, 33, 3, 39, -31, -29, -39, 39, 20, 33, 35, 29, -36, -29, -35, 11, 2, -40, 26, -6, -7, 20, 36, 12, 25, -24, 3, -19, 29, 20, 13, -3, 4, -36, 25, 14, -25, 1, -4, -23};

void findSub(vector<int> &selected, vector<int> &biggest, int pos) {
	if (pos >= nums.size()) {
		if (selected.size() > biggest.size())
			biggest = selected;
		return;
	}

	if (selected.size() == 0) {
		selected.push_back(nums[pos]);
		findSub(selected, biggest, pos + 1);
		selected.pop_back();	
	} 
	else if (nums[pos] >= selected.back()) {
		selected.push_back(nums[pos]);
		findSub(selected, biggest, pos + 1);
		selected.pop_back();		
	}
	
	findSub(selected, biggest, pos + 1);
}

int main() {
	vector<int> selected;
	vector<int> biggest;
	findSub(selected, biggest, 0);
	for (int i : biggest)
		cout << i << ", ";
	cout << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 8962; i <= 9189; i ++) {
		unordered_map<int, bool> usedNums;
		int n = i;
		while (true) {
			int total = 0;
			string s = to_string(n);
			for (char c : s) {
				int x =  c - '0';
				total += x * x;
			}
			if (total == 1) {
				cout << i << ", ";
				break;
			}
			if (usedNums[total])
				break;
			usedNums[total] = true;
			n = total;
		}
	}
}
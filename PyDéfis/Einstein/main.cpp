#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	if (n % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n %  i == 0)
			return false;
	}
	return true;
}

int main() {
	vector<int> nums;
	vector<int> primes = {2};
	for (int i = 3; i < 10000; i++) {
		bool added = false;
		if (isPrime(i)) {
			primes.push_back(i);
			for (int p : primes)
				if ((i * p * p) % 2 == 1 && 
					find(nums.begin(), nums.end(), i * p * p) == nums.end()) {
					nums.push_back(i * p * p);
					added = true;
				}
			for (int p : primes) {
				if ((p * i * i) % 2 == 1 && 
					find(nums.begin(), nums.end(), p * i * i) == nums.end()) {
					added = true;
					nums.push_back(p * i * i);	
				}
			}
			if (added) {
				sort(nums.begin(), nums.end());
				int counter = 1;
				for (int j = 1; j < nums.size(); j++) {
					if ((nums[j] - nums[j - 1]) == 2) {
						counter++;
					}
					else
						counter = 1;
					if (counter == 4) {
						cout << nums[j - 3] << ", " << nums[j - 2] 
						<< ", " << nums[j - 1] << ", " << nums[j];
						return 0;
					}
				}
			}
		}
	}
} 
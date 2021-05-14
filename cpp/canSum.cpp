// Find whether sum is possible from given list
// canSum(7, [4, 3, 7]) -> true

#include <iostream>
#include <vector>
#include <functional>
#include <map>

using namespace std;


bool canSum(int targetSum, vector<int>&& numbers) {

	function<bool(int, vector<int>&)> impl;
	impl = [memo = move(map<int, bool>()), &impl] (int targetSum, vector<int>& numbers) mutable -> bool {
		map<int, bool>::iterator m;
		if ((m = memo.find(targetSum)) != memo.end()) return m->second;
		if (targetSum == 0) return true;
		if (targetSum < 0) return false;

		for (auto num: numbers) {
			int remainder = targetSum - num;
			if (impl(remainder, numbers) == true) {
				memo.emplace(num, true);
				return true;
			}
		}

		memo.emplace(targetSum, false);
		return false;
	};

	return impl(targetSum, numbers);
}

bool canSum(int targetSum, vector<int>& numbers) {
	return canSum(targetSum, move(numbers));
}

int main() {
	vector<int> numbers {5,4,3,7};
	cout << canSum(7, numbers) << endl;	
	// numbers = {7, 14};
	cout << canSum(300, {7, 14}) << endl;	
	cout << canSum(7, {5, 4, 3, 7}) << endl;	
}

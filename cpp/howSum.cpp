// Find the combination from list whose sum is equal to target
// howSum(7, [4, 3, 7]) -> [4, 3] / [7]

#include <iostream>
#include <functional>
#include <vector>
#include <map>

using namespace std;

vector<int> howSum(int targetSum, vector<int>& numbers) {

	function<vector<int>(int, vector<int>&)> impl;
	
	impl = [memo = map<int, vector<int>>(), &impl] (int targetSum, vector<int>& numbers) mutable -> vector<int> {
		map<int, vector<int>>::iterator it;
		if ((it = memo.find(targetSum)) != memo.end()) return move(it->second);
		if (targetSum == 0) return vector<int>(1, 0);
		if (targetSum < 0) return vector<int>();

		for (auto num : numbers) {
			int remainder = targetSum - num;
			vector<int> v = impl(remainder, numbers);

			if (!v.empty()) {
				if (v[0] == 0) v.pop_back();
				v.push_back(num);
				// memo.emplace(targetSum, move(v));
				memo[targetSum] = move(v);
				return memo[targetSum];
			}
		}

		memo[targetSum] = vector<int> ();
		return vector<int> ();
	};

	return impl(targetSum, numbers);
}

int main() {
	vector<int> numbers {3, 4, 7};
	// vector<int> numbers {7, 14};
	// map<int, vector<int>> memo;

	vector<int> result = howSum(7, numbers);
	for (auto i : result)
		cout << i << " ";
	cout << endl;
}

// Find best combination from the list whose sum is equal to target
// bestSum(7, [4, 3, 7]) -> [7]
// bestSum(8, [4, 2]) -> [4, 4]

#include <iostream>
#include <functional>
#include <vector>
#include <map>

using namespace std;


vector<int> bestSum(int target, vector<int>& numbers) {
	function<vector<int>(int, const vector<int>&)> impl;
	impl = [memo = map<int, vector<int>>(), &impl] (int target, const vector<int>& numbers) mutable -> vector<int> {

		map<int, vector<int>>::iterator it;
		if ((it = memo.find(target)) != memo.end()) return it->second;
		if (target == 0) return vector<int>(1, 0);
		if (target < 0) return vector<int>();

		vector<int> shortestCombo;

		for (auto num : numbers) {
			int remainder = target - num;
			vector<int> remainderResult = impl(remainder, numbers);
			if (!remainderResult.empty()) {
				if (remainderResult[0] == 0)
					remainderResult.pop_back();
				remainderResult.push_back(num);
				if (shortestCombo.empty() || shortestCombo.size() > remainderResult.size())
					shortestCombo = move(remainderResult);
			}
		}

		memo[target] = shortestCombo;
		return shortestCombo;
	};

	return impl(target, numbers);
}

vector<int> bestSum(int target, vector<int>&& numbers) {
	return bestSum(target, numbers);
}

int main() {
	vector<int> result = bestSum(6, {2, 3, 4});
	// vector<int> numbers {7, 14};
	// vector<int> result = bestSum(300, {7, 14});

	for (auto i : result)
		cout << i << " ";
	cout << endl;
}

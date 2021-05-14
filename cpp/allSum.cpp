// Find all possible combinations from list whose sum is equal to n
// allSum(7, 4, 3) -> [[4, 3], [3, 4], [7]]

#include <iostream>
#include <functional>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> allSum(int target, const vector<int>& numbers) {
	function<vector<vector<int>>(int, const vector<int>&)> impl;

	impl = [memo=map<int, vector<vector<int>>>(), &impl] (int target, const vector<int>& numbers) mutable -> vector<vector<int>> {

		map<int, vector<vector<int>>>::iterator it;
		if (target == 0) return vector<vector<int>>(1, {0});
		if (target < 0) return vector<vector<int>>();
		if ((it = memo.find(target)) != memo.end()) return it->second;
		
		vector<vector<int>> possibleCombo;

		for (auto num : numbers) {
			int remainder = target - num;
			auto remainderResult = impl(remainder, numbers);
			if (!remainderResult.empty()) {
				if (remainderResult[0][0] == 0)
					remainderResult[0].pop_back();
				remainderResult[0].push_back(num);
				possibleCombo.push_back(move(remainderResult[0]));
			}
		}	

		memo[target] = possibleCombo;
		return possibleCombo;

	};
	
	return impl(target, numbers);
}

vector<vector<int>> allSum(int target, const vector<int>&& numbers) {
	return allSum(target, numbers);
}

int main() {
	map<int, vector<vector<int>>> memo;
	// vector<int> numbers {3, 4, 7};
	// auto result = allSum(7, numbers);

	auto result = allSum(7, {3, 4, 7});

	for (auto v : result) {
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}
}

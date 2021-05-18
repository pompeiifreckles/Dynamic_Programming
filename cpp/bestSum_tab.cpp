#include <iostream>
#include <vector>

using namespace std;

vector<int> bestSum(int target, const vector<int>& numbers) {
	vector<vector<int>> table (target + 1);
	table[0] = {0};

	for (int i = 0; i <= target; i++) {
		if (!table[i].empty()) {
			if (table[i][0] == 0) table[i].pop_back();
			for (auto num : numbers) {
				if (num + i <= target && (table[num + i].empty() || table[num + i].size() > table[i].size())) {
					table[num + i] = table[i];
					table[num + i].push_back(num);
				}
			}
		}
	}

	return table[target];
}

vector<int> bestSum(int target, const vector<int>&& numbers) {
	return bestSum(target, numbers);
}

int main() {
	// auto result = bestSum(7, {4, 3, 7});
	auto result = bestSum(8, {5, 3, 7, 1, 2});
	// auto result = bestSum(300, {7, 14});
	for (auto r : result)
		cout << r << " ";
	cout << endl;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> howSum(int target, const vector<int>& numbers) {
	vector<vector<int>> table (target + 1, vector<int>());
	table[0] = {0};

	for (int i=0; i<=target; i++) {
		if (!table[i].empty()) {
			if (table[i][0] == 0) table[i].pop_back();
			for (auto num : numbers) {
				if (i + num <= target) {
					table[num + i] = table[i];
					table[num + i].push_back(num);
				}
			}
		}
	}

	return table[target];
}

vector<int> howSum(int target, const vector<int>&& numbers) {
	return howSum(target, numbers);
}

int main() {
	auto result = howSum(7, {3, 4, 7});
	for (auto r : result) {
		cout << r << " ";
	}
	cout << endl;
}

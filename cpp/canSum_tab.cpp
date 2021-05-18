#include <iostream>
#include <vector>

using namespace std;

bool canSum(int target, vector<int>&& numbers) {
	vector<bool> table (target + 1, false);
	table[0] = true;
	
	for (int i=0; i<=target; i++) {
		if (table[i])
			for (auto num : numbers) {
				if (i + num <= target)
					table[i + num] = true;
			}
	}

	return table[target];
}

int main() {
	cout << (canSum(7, {3, 4, 7}) ? "true" : "false") << endl;
	cout << (canSum(300, {14, 7}) ? "true" : "false") << endl;
}

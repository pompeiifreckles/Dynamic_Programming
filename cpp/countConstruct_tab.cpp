#include <iostream>
#include <vector>

using namespace std;

int countConstruct(string target, vector<string>& wordBank) {
	vector<int> table (target.size() + 1, 0);
	table[0] = 1;

	for (int i=0; i<=target.size(); i++) {
		if (table[i] != 0)
			for (auto word : wordBank) {
				if (target.compare(i, word.size() + i, word) == 0) {
					table[word.size() + i] += table[i];
				}
			}
	}

	return table[target.size()];
}

int countConstruct(string target, vector<string>&& wordBank) {
	return countConstruct(target, wordBank);
}

int main() {
	cout << countConstruct("abcdef", {"ef", "ab", "bc", "abc", "def", "abcd"}) << endl;
	cout << countConstruct("skateboard", {"ab", "bc", "abc", "def", "abcd"}) << endl;
}

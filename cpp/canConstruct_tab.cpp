// canConstruct(target, wordBank)
//
// canConstruct(abcdef, [ab, abc, cd, def, abcd]) -> true

#include <iostream>
#include <vector>

using namespace std;

bool canConstruct(string target, const vector<string>& wordBank) {
	vector<bool> table (target.size() + 1, false);
	table[0] = true;

	for (int i = 0; i <= target.size(); i++) {
		if (table[i])
		for (auto word : wordBank) {
			if (target.compare(i, word.size() + i, word) == 0) {
				table[word.size() + i] = true;
			}
		}
	}

	return *(table.end() - 1);
}

bool canConstruct(string target, const vector<string>&& wordBank) {
	return canConstruct(target, wordBank);
}

int main() {
	cout << (canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) ? "true" : "false") << endl;
	cout << (canConstruct("skateboard", {"ab", "abc", "cd", "def", "abcd"}) ? "true" : "false") << endl;
}

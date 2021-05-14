// canConstruct(target, wordBank) returns boolean indicating if    
// target can be combination of concatednated strings in wordBank    
// string re-use possible    
//    
// canConstruct(abcdef, [ab, abc, cd, def, abcd]) -> true    
// canConstruct(skateboard, [ab, abc, cd, def, abcd]) -> false   

#include <iostream>
#include <vector>

using namespace std;

bool canConstruct(string target, const vector<string>& wordBank) {
	if (target == "") return true;

	for (auto word : wordBank) {
		int size = word.size();
		if (target.compare(0, size, word) == 0) {
			bool result = canConstruct(target.substr(0, target.size() - word.size()), wordBank);
			if (result) return true;
		}
	}

	return false;
}

int main() {
	vector<string> wordBank {"ab", "abc", "cd", "def", "abcd"};

	auto result = canConstruct("abcdef", wordBank);
	cout << ((result) ? "true" : "false") << endl;

	result = canConstruct("skateboard", wordBank);
	cout << ((result) ? "true" : "false") << endl;
}

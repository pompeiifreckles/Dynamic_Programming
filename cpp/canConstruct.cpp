// canConstruct(target, wordBank) returns boolean indicating if    
// target can be combination of concatednated strings in wordBank    
// string re-use possible    
//    
// canConstruct(abcdef, [ab, abc, cd, def, abcd]) -> true    
// canConstruct(skateboard, [ab, abc, cd, def, abcd]) -> false   

#include <iostream>
#include <functional>
#include <vector>
#include <map>

using namespace std;

bool canConstruct(string target, const vector<string>& wordBank) {
	function<bool(string, const vector<string>&)> impl;
	impl = [memo=map<string, bool>(), &impl] (string target, const vector<string>& wordBank) mutable -> bool {

		map<string, bool>::iterator it;
		if ((it = memo.find(target)) != memo.end()) return it->second;
		if (target == "") return true;

		for (auto word : wordBank) {
			int size = word.size();
			if (target.compare(0, size, word) == 0) {
				bool result = impl(target.substr(0, target.size() - word.size()), wordBank);
				if (result) {
					memo[target] = true;
					return true;
				}
			}
		}

		memo[target] = false;
		return false;
	};

	return impl(target, wordBank);
}

bool canConstruct(string target, const vector<string>&& wordBank) {
	return canConstruct(target, wordBank);
}

int main() {
	vector<string> wordBank {"ab", "abc", "cd", "def", "abcd"};

	auto result = canConstruct("abcdef", wordBank);
	cout << ((result) ? "true" : "false") << endl;

	result = canConstruct("skateboard", wordBank);
	cout << ((result) ? "true" : "false") << endl;
}

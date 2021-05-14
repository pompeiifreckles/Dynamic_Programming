// countConstruct(abcdef, [ab, cd, abc, def, abcd]) -> 1    
// countConstruct(purple, [purp, p, ur, le, purpl]) -> 2

#include <iostream>
#include <functional>
#include <vector>
#include <map>

using namespace std;

int countConstruct(string target, const vector<string>& wordBank) {
	function<int(string, const vector<string>&)> impl;
	impl = [memo=map<string, int>(), &impl] (string target, const vector<string>& wordBank) mutable -> int {

		map<string, int>::iterator it;
		if ((it = memo.find(target)) != memo.end()) return it->second;
		if (target == "") return 1;	

		int count {0};
		for (auto word : wordBank) {
			size_t size {word.size()};
			if (target.compare(0, word.size(), word) == 0) {
				auto result = impl(target.substr(word.size(), target.size() - word.size()), wordBank);

				count += result;
			}
		}

		memo[target] = count;
		return count;
	};

	return impl(target, wordBank);
}

int countConstruct(string target, const vector<string>&& wordBank) {
	return countConstruct(target, wordBank);
}

int main() {
	// vector<string> wordBank {"ab", "cd", "abc", "def", "abcd"};
	int result = countConstruct("purple", {"purp", "p", "ur", "le", "purpl"});
	cout << result << endl;
}

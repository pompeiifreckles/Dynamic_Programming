// allConstruct(target, wordBank) return 2D array
// containing all possible combinations 
//  
// allConstruct(purple, [purp, p, le, ur, purpl]) 
// [    
//      [purp, le],    
//      [p, ur, p, le]    
// ]    

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<vector<string>> allConstruct(string target, const vector<string>& wordBank) {

	function< vector<vector<string>>(string, const vector<string>&) > impl;
	impl = [memo= map<string, vector<vector<string>>>() , &impl] (string target, const vector<string>& wordBank) mutable {
		if (auto ret_it = memo.find(target); ret_it != memo.end()) return ret_it->second;
		if (target == "") return vector<vector<string>>(1);

		vector<vector<string>> possibleCombo;
		for (auto word : wordBank) {
			if (target.compare(0, word.size(), word) == 0) {
				string suffix = target.substr(word.size(), target.size() - word.size());
				auto suffixCombo = impl(suffix, wordBank);
				for (auto& suffixWay: suffixCombo) {
					suffixWay.insert(suffixWay.begin(), word);
					// suffixWay.push_back(word);
					possibleCombo.push_back(move(suffixWay));
				}
			}
		}

		auto it = memo.emplace(target, move(possibleCombo));
		return it.first->second;
	};

	return impl(target, wordBank);
}


vector<vector<string>> allConstruct(string target, const vector<string>&& wordBank) {
	return allConstruct(target, wordBank);
}

int main() {
	// vector<string> wordBank {"p", "purp", "ur", "le", "purpl"};
	// auto result = allConstruct("purple", wordBank);
	auto result = allConstruct("purple", {"p", "purp", "ur", "le", "purpl"});

	for (auto& i : result) {
		// reverse(i.begin(), i.end());
		for (auto m : i)
			cout << m << " ";
		cout << endl;
	}
}

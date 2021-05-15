// allConstruct(target, wordBank) return 2D array
// containing all possible combinations 
//  
// allConstruct(purple, [purp, p, le, ur, purpl]) 
// [    
//      [purp, le],    
//      [p, ur, p, le]    
// ]    

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<string>> allConstruct(string target, const vector<string>& wordBank, map<string, vector<vector<string>>>& memo) {
	map<string, vector<vector<string>>>::iterator ret_it;
	if ((ret_it = memo.find(target)) != memo.end()) return ret_it->second;
	if (target == "") return vector<vector<string>>(1);

	vector<vector<string>> possibleCombo;
	for (auto word : wordBank) {
		if (target.compare(0, word.size(), word) == 0) {
			string suffix = target.substr(word.size(), target.size() - word.size());
			auto suffixCombo = allConstruct(suffix, wordBank, memo);
			for (auto& suffixWay: suffixCombo) {
				suffixWay.insert(suffixWay.begin(), word);
				// suffixWay.push_back(word);
				possibleCombo.push_back(move(suffixWay));
			}
		}
	}

	auto it = memo.emplace(target, move(possibleCombo));
	return it.first->second;
}

int main() {
	map<string, vector<vector<string>>> memo;
	vector<string> wordBank {"p", "purp", "ur", "le", "purpl"};
	auto result = allConstruct("purple", wordBank, memo);
	// vector<string> wordBank {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
	// auto result = allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", wordBank, memo);

	for (auto& i : result) {
		// reverse(i.begin(), i.end());
		for (auto m : i)
			cout << m << " ";
		cout << endl;
	}
}

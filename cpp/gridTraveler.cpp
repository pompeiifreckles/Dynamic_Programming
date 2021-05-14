// grid traveler for m x n grid
// possible movements - down, left
// start -> top-left, end -> bottom-right

#include <iostream>
#include <functional>
#include <string>
#include <map>

using namespace std;

long gridTraveler(int m, int n) {
	function<long(int, int)> impl;
	
	impl = [memo=map<string, int>(), &impl] (int m, int n) mutable -> long {
		string key = to_string(m) + "," + to_string(n);
		map<string, int>::iterator it;
		if ((it = memo.find(key)) != memo.end()) return it->second;
		if (m == 1 && n == 1) return 1;
		if (m == 0 || n == 0) return 0;

		long result = static_cast<long>(impl(m-1, n)) + static_cast<long>(impl(m, n-1));

		memo[key] = result;
		return result;
	};

	return impl(m, n);
}

int main() {
	auto result = gridTraveler(300, 300);
	cout << result << endl;
}

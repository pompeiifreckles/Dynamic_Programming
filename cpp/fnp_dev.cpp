// Find G(n) if G(n) = 2*G(n) - 3*G(n-1) + G(n-3)    
// G(1) = 5, G(2) = 3, G(3) = 3 

#include <iostream>
#include <functional>
#include <map>

using namespace std;

unsigned long long fnp(int n) {
	function< unsigned long long(int) > impl;
	impl = [&impl, memo = map<int, unsigned long long>()] (int n) mutable -> unsigned long long {

		if (auto it = memo.find(n); it != memo.end()) return it->second;
		if (n == 1) return 5;
		if (n == 2 || n == 3) return 3;

		auto ret_it = memo.emplace(n, 3*impl(n-1) - impl(n-3));
		return ret_it.first->second;
	};

	return impl(n);
}


int main() {
	cout << fnp(1) << endl
	<< fnp(2) << endl 
	<< fnp(3) << endl
	<< fnp(22) << endl
	<< fnp(79) << endl;
}

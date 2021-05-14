// Find fibonacci number at n position
// fib(3) -> 1

#include <iostream>
#include <map>
#include <functional>

using namespace std;

long fib(int n) {

	function<long(int)> impl = [memo=move(map<long, long>()), &impl] (int n) mutable -> long {
		if (n == 0) return 0;
		if (n == 1 || n == 2) return 1;
		map<long, long>::iterator l;
		if ( (l = memo.find(n)) != memo.end()) {
			return (*l).second;
		}

		long m = impl(n-1) + impl(n-2);

		memo.emplace(n, m);
		return m;
	};

	return impl(n);
}

int main() {
	cout << fib(100) << endl;
}

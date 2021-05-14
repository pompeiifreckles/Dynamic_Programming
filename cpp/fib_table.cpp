// Find fibonacci number at n position using tabulation
// fib(3) -> 1

#include <iostream>
#include <vector>

using namespace std;

long fib(int n) {
	vector<long> table (n+1, 0);
	table[1] = 1;
	
	for (int i=0; i<=n; i++) {
		if (i + 1 <= n) table[i+1] += table[i];
		if (i + 2 <= n) table[i+2] += table[i];
	}

	return table[n];
}

int main() {
	for (int i=0; i<10; i++)
		cout << fib(i) << endl;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gridTraveler(int m, int n) {
	vector<vector<int>> table;
	fill_n(back_inserter(table), n, vector<int>(m, 0));

	table[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (table[i][j] != 0) {
				if (i + 1 < n) table[i + 1][j] += table[i][j];
				if (j + 1 < m) table[i][j + 1] += table[i][j];
			}
		}
	}

	return table[n-1][m-1];
}

int main() {
	cout << gridTraveler(2, 2) << endl;
	cout << gridTraveler(1, 1) << endl;
	cout << gridTraveler(3, 3) << endl;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main () {
	int n, m;
	cin >> n >> m;

	int	memo[101][101];

	for (int i=0; i<=n; ++i) {
		for (int j=0; j<=m; ++j) {
			if (i==0 && j==0) memo[i][j] = 1;
			else if (i==0) memo[i][j] = 0;
			else if (j==0) memo[i][j] = 1;
			else if (i*m < j*n) memo[i][j] = 0;
			else memo[i][j] = memo[i-1][j] + memo[i][j-1];
		}
	}

	cout << memo[n][m] << endl;
	return 0;
}


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
using namespace std;

int C, N, T[101][101], Memo[101][101];

int Solve (int y, int x) {
	if (y == N) return 0;

	int &ret = Memo[y][x];
	if (ret != -1) return ret;

	ret = T[y][x] + max (Solve(y+1, x), Solve(y+1, x+1));
	return ret;
}

int main () {
	cin >> C;

	while (C--) {
		cin >> N;
		for (int i=0; i<N; ++i)
			for (int j=0; j<=i; ++j)
				scanf("%d", &T[i][j]);

		memset (Memo, -1, sizeof(Memo));

		cout << Solve(0, 0) << endl;
	}

	return 0;
}


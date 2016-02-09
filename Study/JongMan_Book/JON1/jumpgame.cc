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

int C, N, A[101][101], Memo[101][101];

int Solve (int y, int x) {
	if (y == N-1 && x == N-1) return 1;
	else if (y>= N || x >= N) return 0;

	int &ret = Memo[y][x];
	if (ret != -1) return ret;

	ret = 0;

	return ret = Solve (y+A[y][x], x) | Solve (y, x+A[y][x]);
}


	
int main () {
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				scanf("%d", &A[i][j]);

		memset(Memo, -1, sizeof(Memo));

		if (Solve(0, 0)) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}


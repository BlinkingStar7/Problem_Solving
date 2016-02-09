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

int C, N, A[101][101], Memo[101][101], Memo2[101][101];

int Solve (int y, int x) {
	if (y == N) return 0;

	int &ret = Memo[y][x];
	if (ret != -1) return ret;

	ret = A[y][x];

	return ret += max (Solve (y+1, x), Solve(y+1,x+1));
}

int Solve2 (int y, int x) {
	if (y == N-1) return 1;

	int &ret = Memo2[y][x];
	if (ret != -1) return ret;

	ret = 0;

	if (Solve (y, x) == A[y][x] + Solve(y+1, x)) ret += Solve2(y+1, x);
	if (Solve (y, x) == A[y][x] + Solve(y+1, x+1)) ret += Solve2(y+1, x+1);

	return ret;
}

int main () {
	cin >> C;

	while (C--) {
		cin >> N;
		for (int i=0; i<N; ++i)
			for (int j=0; j<=i; ++j)
				scanf("%d", &A[i][j]);

		memset(Memo, -1, sizeof(Memo));
		memset(Memo2, -1, sizeof(Memo2));

		Solve (0, 0);
		cout << Solve2(0, 0) << endl;

	}


	return 0;
}


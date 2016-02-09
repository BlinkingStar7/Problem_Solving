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

int N, M, A[201][201], memo[201][201];

int Solve(int y, int x) {
	if (y == N && x == M) return A[y][x];

	int &ret = memo[y][x];
	if (ret != -1) return ret;

	ret = 0;

	if (y != N) ret = max(ret, A[y][x] + Solve(y+1, x));
	if (x != M) ret = max(ret, A[y][x] + Solve(y, x+1));
	return ret;
}

int main () {

	cin >> N >> M;

	for (int i=1; i<=N; ++i)
		for (int j=1; j<=M; ++j)
			scanf("%d", &A[i][j]);
	memset(memo, -1, sizeof(memo));
	cout << Solve(1, 1) << endl;
	return 0;
}


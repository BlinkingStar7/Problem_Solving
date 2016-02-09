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
#define MAX 987654321

int N, A[21][21], Memo[21][1<<20];

int Solve (int r, int c) {
	if (r == N) return 0;

	int &ret = Memo[r][c];
	if (ret != -1) return ret;

	ret = MAX;

	for (int n=0; n<N; ++n) {
		if ((c & 1 << n) == 0)
			ret = min (ret, A[r][n] + Solve(r+1, c | 1 << n));
	}

	return ret;
}

int main () {
memset(Memo, -1, sizeof(Memo));
	cin >> N;
	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j)
			scanf("%d", &A[i][j]);

	cout << Solve(0, 0) << endl;
	return 0;
}


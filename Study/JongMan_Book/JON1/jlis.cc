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
#include <limits>
using namespace std;

int C, N, M, Memo[102][102];
long long A[101], B[101];

int Solve (int a, int b) {
	int &ret = Memo[a+1][b+1];
	if (ret != -1) return ret;

	ret = 2;
	long long m = numeric_limits<long long>::min();
	if (a != -1) m = A[a];
	if (b != -1) m = max (m, B[b]);

	for (int next = a+1; next<N; ++next)
		if (A[next] > m)
			ret = max (ret, 1 + Solve(next, b));
	
	for (int next = b+1; next<M; ++next)
		if (B[next] > m)
			ret = max (ret, 1 + Solve(a, next));
	return ret;
}

int main () {
	cin >> C;

	while (C--) {
		cin >> N >> M;
		for (int i=0; i<N; ++i)
			scanf("%lld", A+i);
		for (int i=0; i<M; ++i)
			scanf("%lld", B+i);
		memset(Memo, -1, sizeof(Memo));

		cout << Solve (-1, -1) - 2 << endl;


	}


	return 0;
}


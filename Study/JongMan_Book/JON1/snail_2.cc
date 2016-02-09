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

int C, N, M;
double Memo[1001][2003];

double Solve (int m, int p) {
	if (m == M) return p >= N ? 1 : 0;
	if (p >= N) return 1;

	double &ret = Memo[m][p];
	if (ret != -1) return ret;

	return ret = 0.25*Solve(m+1, p+1) + 0.75*Solve(m+1,p+2);
}

int main () {
	cin >> C;

	while (C--) {
		cin >> N >> M;

		for (int i=0; i<N; ++i)
			for (int j=0; j<=2*M; ++j)
				Memo[i][j] = -1;
		printf("%.10lf\n", Solve(0, 0));

	}

	return 0;
}


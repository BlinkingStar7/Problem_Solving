#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define SQR(x) ((x)*(x))
#define MAX 987654321
using namespace std;

int N, K, memo[12][11][142], Gx[1001], Gy[1001];

int Fuel (int cur, int to) {
	int ret = SQR(Gx[cur] - Gx[to]) + SQR(Gy[cur] - Gy[to]);
	return ceil(sqrt(ret)/10);
}

int Solve (int cur, int k, int m) {
	if (cur == N) return m;
	else if (k == 0) return max (m, Fuel(cur, N));

	int &ret = memo[cur+1][k][m];
	if (ret != -1) return ret;

	ret = MAX;
	
	for (int next=0; next<N; ++next) {
		int cand = Fuel(cur, next);
		ret = min (ret, Solve(next, k-1, max(cand, m)));
	}

	return ret;
}

int main() {
	cin >> N >> K;
	
	memset(memo, -1, sizeof(memo));
	for (int i=0; i<N; ++i) {
		scanf("%d", Gx + i);
		scanf("%d", Gy + i);
	}

	Gx[N] = Gy[N] = 10000;

	cout << Solve (-1, K, 0) << endl;
	return 0;
}



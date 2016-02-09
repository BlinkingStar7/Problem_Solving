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
#define MIN -987654321
long long N, K, X, memo[200001][11];
int A[200001];
long long Solve (int n, int k) {
	if (n == N) return 0;
	if (k == 0) return (long long)A[n] | Solve (n+1, k);
	
	long long &ret = memo[n][k];
	if (ret != -1) return ret;

	ret = MIN;
	long long x = 1;
	for (int i=0; i<=k; ++i) {
		ret = max (ret, ((long long)A[n]*x) | (Solve(n+1, k-i)));
		x *= X;
	}
	return ret;
}

int main () {
	cin >> N >> K >> X;

	memset(memo, -1, sizeof(memo));
	for (int i=0; i<N; ++i)
		scanf("%d", &A[i]);
	
	int n, k;

	cout << Solve(0, K) << endl;

	return 0;
}


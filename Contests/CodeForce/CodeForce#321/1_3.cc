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

int N, A[100001], Memo[100001];

int Solve (int k) {
	if (k == N-1) return 1;

	int &ret = Memo[k+1];
	if (ret != -1) return ret;

	if (k == -1) return ret = 1+Solve(k+1);
	return ret = (A[k] <= A[k+1]) ? 1+Solve(k+1) : 1;
}

int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		scanf("%d", &A[i]);
	memset(Memo, -1, sizeof(Memo));

	cout << Solve(-1)-1 << endl;
	return 0;
}


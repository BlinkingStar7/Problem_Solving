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
#define MAX 987654321
int C, N, S, A[101], Sum[101][101], Sq[101][101], Memo[101][11];

int Solve (int p, int k) {
	if (p == N) return 0;
	if (k == 0) return MAX;

	int &ret = Memo[p][k];
	if (ret != -1) return ret;

	ret = MAX;

	for (int next = p+1; next <=N; ++next) {
		int x = Sum[p][next-1] / (double)(next-p) + 0.5;
		ret = min (ret, Solve (next, k-1) + Sq[p][next-1] -2*Sum[p][next-1]*x + (next-p)*x*x);
	}

	return ret;
}


int main () {
	cin >> C;

	while (C--) {
		cin >> N >> S;
		for (int i=0; i<N; ++i)
			scanf("%d", A+i);

		sort (A, A+N);
		for (int s=0; s<N; ++s)
			for (int t=s; t<N; ++t)
				if (s == t) Sum[s][t] = A[s], Sq[s][t] = A[s]*A[s];
				else Sum[s][t] = Sum[s][t-1] + A[t], Sq[s][t] = Sq[s][t-1] + A[t]*A[t];
		
		memset (Memo, -1, sizeof(Memo));
		cout << Solve (0, S) << endl;

	}


	return 0;
}


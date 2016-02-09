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

int C, N, D, P, A[51][51], G[51], T;
double M[101][51];

double Solve(int d, int cur) {
	if (d == 0) return cur == P ? 1.0 : 0.0;

	double &ret = M[d][cur];
	if (ret != -1)return ret;

	ret = 0.0;
	for (int bef = 0; bef <N; ++bef) {
		if (A[cur][bef]) {
			ret +=  Solve(d-1, bef)/G[bef];
		}
	}

	return ret ;
}

int main () {
	cin >> C;

	while (C--) {
		cin >> N >> D >> P;
		for (int i=0; i<N; ++i) {
			int num = 0;
			for (int j=0; j<N; ++j) {
				scanf("%d", &A[i][j]);
				if (A[i][j]) ++num;
			}
			G[i] = num;
		}
		cin >> T;

			for (int i=0; i<=D; ++i)
				for (int j=0; j<N; ++j)
					M[i][j] = -1;
		for (int i=0; i<T; ++i) {
			int t;
			cin >> t;
			printf("%.8lf ", Solve(D, t));
		}
		cout << endl;


	}


	return 0;
}


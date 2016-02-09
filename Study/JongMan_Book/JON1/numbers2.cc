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

int main () {
	cin >> C;

	while (C--) {
		cin >> N >> D >> P;
		for (int i=0; i<N; ++i) {
			int num =0;
			for (int j=0; j<N; ++j) {
				scanf("%d", &A[i][j]);
				if (A[i][j]) ++num;
			}
			G[i] = num;
		}
		cin >> T;

		double M[101][51];

		memset (M, 0, sizeof(M));

		M[0][P] = 1.0;

		for (int d=1; d<=D; ++d) {
			for (int v=0; v<N; ++v) {	
				for (int b=0; b<N; ++b)
					if (A[b][v]) M[d][v] += M[d-1][b] / G[b];
			}
		}


		for (int i=0; i<T; ++i) {
			int v;
			cin >> v;
			printf("%.8lf ", M[D][v]);
		}
		puts("");

	}


	return 0;
}


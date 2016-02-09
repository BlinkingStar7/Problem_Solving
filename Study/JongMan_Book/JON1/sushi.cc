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

int C, N, M, P[21], L[21];

int main () {
	cin >> C;

	while (C--) {
		cin >> N >> M;
		for (int i=0; i<N; ++i) {
			cin >> P[i] >> L[i];
			P[i] /= 100;
		}
		M /= 100;

		int D[201];
		memset(D, 0, sizeof(D));

		for (int i=1; i<=M; ++i) {
			for (int s=0; s<N; ++s) {
				if (i-P[s] >= 0)
					D[i%201] = max (D[i%201], D[(i-P[s]+201)%201] + L[s]);
			}
		}

		cout << D[M%201] << endl;


	}


	return 0;
}


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

int N, P[801], S[801][801];

int main () {
	cin >> N;
	int cnt = 0;
	for (int i=2; i<=2*N; ++i) {
		for (int j=1; j<i; ++j) {
			scanf("%d", &S[i][j]);
		}
	}

	while (cnt != 2*N) {
		int max = 0, mi = -1, mj = -1;
		for (int i=2; i<=2*N; ++i) {
			for (int j=1; j<i; ++j) {
				if (P[i]) break;
				else if (P[j]) continue;
				if (S[i][j] > max) {
					max = S[i][j];
					mi = i;
					mj = j;
				}
			}
		}

		P[mi] = mj;
		P[mj] = mi;
		cnt += 2;
	}

	for (int i=1; i<=2*N; ++i)
		printf("%d ", P[i]);

	return 0;
}


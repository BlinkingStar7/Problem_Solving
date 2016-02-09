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

int C, N, T[101][101], Memo[101][101];

int main () {
	cin >> C;

	while (C--) {
		cin >> N;
		for (int i=0; i<N; ++i)
			for (int j=0; j<=i; ++j)
				scanf("%d", &T[i][j]);

		memset (Memo, 0, sizeof(Memo));

		for (int i=0; i<N; ++i)
			for (int j=0; j<=i; ++j) {
				Memo[i][j] = T[i][j];
				if (i >= 1) {
					if (j >= 1) Memo[i][j] += max (Memo[i-1][j], Memo[i-1][j-1]);
					else Memo[i][j] += Memo[i-1][j];
				}
			}
		int a = Memo[N-1][0];
		for (int i=0; i<N; ++i)
			if (Memo[N-1][i] > a) a= Memo[N-1][i];
		cout << a << endl;
	}

	return 0;
}


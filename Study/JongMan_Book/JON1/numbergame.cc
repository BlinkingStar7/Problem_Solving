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

int C, N, A[51], Memo[51][51], S[51][51];
const int MAX = 987654321;
int Solve (int lo, int hi) {
	if (lo == hi) return A[lo];
	if (lo == hi-1) return max(0, max(A[lo] - A[hi], A[hi] - A[lo]));

	int &ret = Memo[lo][hi];
	if (ret != MAX) return ret;

	int cand1 = max (A[lo] - Solve(lo+1, hi), A[hi] - Solve(lo, hi-1));
	int cand2 = max (-Solve(lo+2, hi), -Solve(lo, hi-2));
	return ret = max (cand1, cand2);
}

int main () {
	cin >> C;

	while (C--) {
		cin >> N;
		for (int i=0; i<N; ++i) {
			cin >> A[i];
		}

		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				Memo[i][j] = MAX;

		for (int i=0; i<N; ++i)
			for (int j=i; j<N; ++j) {
				if (j == i) S[i][j] = A[i];
				else S[i][j] = S[i][j-1] + A[j];
			}

		cout << Solve(0, N-1)<< endl;

	}


	return 0;
}


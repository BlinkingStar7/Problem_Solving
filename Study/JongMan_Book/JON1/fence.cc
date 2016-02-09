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

int C, N, A[20001];

int Solve (int lo, int hi) {
	if (lo == hi) return A[lo];

	int mid = (lo+hi)/2;
	int cand = max (Solve(lo, mid), Solve(mid+1, hi));

	int a=mid, b=mid+1, h = min(A[a], A[b]), s=h*(b-a+1);

	while (1) {
		if (a==lo && b==hi) break;
		if (a==lo || (b!=hi && A[a-1] < A[b+1]))
			h = min (h, A[++b]);
		else h = min (h, A[--a]);
		s = max (s, h*(b-a+1));
	}

	return max (s, cand);
}

int main () {
	cin >> C;

	while (C--) {
		cin >> N;
		for (int i=0; i<N; ++i)
			scanf("%d",&A[i]);

		cout << Solve (0, N-1) << endl;
	}

	return 0;
}


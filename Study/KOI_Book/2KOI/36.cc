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

int N;
pair<int, int> A[100001];

int Solve (int lo, int hi) {
	if (lo == hi) return 1;
	int mid = (lo+hi)/2;

	int cand = max (Solve(lo,mid), Solve(mid+1,hi));

	int left, right;
	for (left=mid; left>=lo; --left)
		if (A[left].second > A[left+1].second)
			break;
	for (right=mid+1; right<=hi; ++right)
		if (A[right].second < A[right-1].second)
			break;

	return max (cand, right - left - 1);
	 
}


int main () {

	cin >> N;

	for (int i=0; i<N; ++i) 
		scanf("%d %d", &A[i].first, &A[i].second);

	sort (&A[0], &A[N]);

	cout << Solve (0, N-1) << endl;

	return 0;
}


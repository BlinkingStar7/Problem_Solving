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

int C, N, A[501], Memo[502];

int Solve(int i) {
	int &ret = Memo[i+1];
	if (ret != -1) return ret;

	ret = 1;

	for (int next = i+1; next < N; ++next)
		if (i == -1 || A[next] > A[i]) 
			ret = max (ret, 1 + Solve(next));
	return ret;
}

int main () {
	cin >> C;

	while (C--) {
		cin >> N;
		for (int i=0; i<N; ++i)
			scanf("%d", &A[i]);
		memset(Memo, -1, sizeof(Memo));
		cout << Solve(-1) - 1 << endl;
	}


	return 0;
}


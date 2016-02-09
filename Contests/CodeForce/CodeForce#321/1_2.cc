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

int N, A[100001], Memo[100001];

int Solve(int k) {
	int &ret = Memo[k+1];
	if (ret != -1) return ret;

	ret = 1;

	for (int next=k+1; next<N; ++next) 
		if (k == -1 || A[next] >= A[k])
			ret = max (ret, 1 + Solve(next));

	return ret;
}

int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		scanf("%d", &A[i]);

	memset(Memo, -1, sizeof(Memo));
	cout << Solve(-1) - 1<< endl;

	return 0;
}


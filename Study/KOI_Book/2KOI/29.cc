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

int N, D[21], S[21], A[21], Memo[21][21][21];

int canReach1(int f, int t) {
	return D[t] - D[f] <= S[f];
}

int canReach2(int f, int t) {
	return A[f] && (D[t] - D[f] <= S[t]);
}

int Solve(int a, int b, int p) {
	if (p == N-1)
		return canReach1(a, p) && canReach2(b, p) ? 1 : 0;

	int &ret = Memo[a][b][p];
	if (ret != -1) return ret;

	ret = Solve(a, b, p+1);
	if (canReach1(a, p)) ret += Solve(p, b, p+1);
	if (canReach2(b, p)) ret += Solve(a, p, p+1);

	return ret;
}

int main () {
	memset(Memo, -1, sizeof(Memo));

	cin >> N;
	for (int i=0; i<N; ++i)
		cin >> D[i] >> S[i] >> A[i];

	cout << Solve(0, 0, 1) << endl;
	return 0;
}


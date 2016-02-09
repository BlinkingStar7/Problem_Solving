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
#define MAX 987654321

int N, P[21], S, Min = MAX, Memo[2001][2001][20];

int Solve (int a, int b, int c, int p) {
	int rest = S-a-b-c;
	if (b > S/ 2 || c > S/ 3) return MAX;
	if (a + rest < b || b + rest < c) return MAX;
	if (a - (c + rest) > Min) return MAX;

	if (p == N) {
		if (a < b || b < c)
			return MAX;
		if (a - c < Min)
		return a - c;
	}

	int &ret = Memo[a][b][p];
	if (ret != -1) return ret;

	int cand = min (Solve(a+P[p], b, c, p+1), Solve(a, b+P[p], c, p+1));
	return min (Solve(a, b, c+P[p], p+1), cand);
}

int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		cin >> P[i];

	S[0] = P[0];

	for (int i=1; i<N; ++i)
		S[i] = S[i-1] + P[i];

	memset(Memo, -1, sizeof(Memo));
	cout << Solve(0, 0, 0) << endl;

	return 0;
}


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

int memo[501][501][501], N, P[501], S[501], G[501];

bool canReach (int from, int to) { return P[to] - P[from] <= S[from]; }
bool canReach2 (int from, int to) { return (P[to] - P[from] <= S[to]) && G[to];}

int Solve (int aPos, int bPos, int next) {
	if (next == N - 1) 
		if (canReach(aPos, next) && canReach2(bPos, next)) return 1;
		else return 0;

	int &ret = memo[aPos][bPos][next];
	if (ret != -1) return ret;

	ret = 0;

	if (canReach(aPos, next)) ret += Solve(next, bPos, next+1) % 1000;
	if (canReach2(bPos, next)) ret += Solve(aPos, next, next+1) % 1000;
	ret += Solve(aPos, bPos, next+1) % 1000;
	return ret;
}

int main () {
	cin >> N;
	memset(memo, -1, sizeof(memo));

	for (int i=0; i<N; ++i)
		scanf("%d %d %d", P+i, S+i, G+i);

	cout << Solve(0, 0, 1) << endl;
	return 0;
}


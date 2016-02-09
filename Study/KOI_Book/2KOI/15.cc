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

int N, M, A, B, X, Y, Edge[501];

int Solve(int m, int p, int cost) {
	if (m == M) return p == B ? 0 : MAX;
	if (p <= 0 || p > N) return MAX;
	if (cost > ans) return MAX;

	int &ret = memo[m][p];
	if (ret != -1) return ret;
	
	int cand1, cand2;

	if (Edge[m] == cur || Edge[m] == cur - 1) {
		int next = Edge[m] == cur ? cur+1 : cur-1;
		cand1 = min (Solve(m+1,next), X+Solve(m+1,cur));
	}

	cand2 = min (Y+Solve(m, p+1), Y+Solve(m, p-1));
	return ret = min (cand1, cand2);
}

int main () {
	cin >> N >> M >> A >> B >> X >> Y;

	for (int i=0; i<M; ++i)
		cin >> Edge[i];
	
	memset(memo, -1, sizeof(memo));

	return 0;
}


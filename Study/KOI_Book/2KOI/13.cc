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

int N, W, C[101], M[101], memo[101][10001];

int Solve(int n, int w) {
	if (n == N) return 0;

	int &ret = memo[n][w];
	if (ret != -1) return ret;

	ret = Solve (n+1, w);
	if (w + M[n] <= W) ret = max (ret, C[n] + Solve(n+1, w+M[n]));
	return ret;
}
int main () {
	cin >> N >> W;
	memset(memo, -1, sizeof(memo));
	for (int i=0; i<N; ++i) {
		cin >> M[i];
		cin >> C[i];
	}

	cout << Solve (0, 0) << endl; 
	return 0;
}


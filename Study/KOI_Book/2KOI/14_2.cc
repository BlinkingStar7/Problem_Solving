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
int N, M, Mem[101], Cost[101], memo[101][101*100];

int Solve(int n, int c) {
	if (n == -1) return 0;

	int &ret = memo[n][c];
	if (ret != -1) return ret;

	ret = Solve(n-1, c);
	if (c >= Cost[n]) ret = max (ret, Solve(n-1, c-Cost[n]) + Mem[n]);
	
	return ret;
}


int main () {
	cin >> N >> M;
	for (int i=0; i<N; ++i)
		cin >> Mem[i];
	for (int i=0; i<N; ++i)
		cin >> Cost[i];
	memset(memo, -1, sizeof(memo));

	for (int i=0; i<N*101; ++i)
		if (Solve(N-1, i) >= M) {
			cout << i << endl;
			return 0;
		}

	return 0;
}


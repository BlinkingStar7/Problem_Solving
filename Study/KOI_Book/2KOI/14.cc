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


int main () {
	cin >> N >> M;
	for (int i=0; i<N; ++i)
		cin >> Mem[i];
	for (int i=0; i<N; ++i)
		cin >> Cost[i];

	memo[0][Cost[0]] = Mem[0];
	for (int n=1; n<N; ++n) {
		for (int c=1; c<=N*100; ++c) {
			memo[n][c] = memo[n-1][c];
			if (c >= Cost[n]) memo[n][c] = max (memo[n-1][c], memo[n-1][c-Cost[n]] + Mem[n]);
		}
	}

	for (int c=0; c<=N*100; ++c)
		if (memo[N-1][c] >= M) {
			cout << c << endl;
			return 0;
		}
	return 0;
}


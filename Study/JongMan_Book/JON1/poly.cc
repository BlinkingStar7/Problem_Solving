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

#define MOD 10000000
#define MAX 987654321
int C, N, Memo[101][101];

int Solve (int p, int k) {
	if (k == 0) return 1;
	
	int &ret = Memo[p][k];
	if (ret != -1) return ret;

	ret = 0;

	for (int i=1; i<=k; ++i)
		ret = (ret + (p == 0 ? 1 : p+i-1) * Solve(i, k-i)) % MOD;
	return ret;
}

int main () {
	cin >> C;

	while (C--) {
		cin >> N;
		memset(Memo, -1, sizeof(Memo));
		cout << Solve (0, N) << endl;
	}


	return 0;
}


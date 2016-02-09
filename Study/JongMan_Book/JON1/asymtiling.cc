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
#define MOD 1000000007

int C, N, D[101], M[101];

int main () {
	cin >> C;

	D[0] = D[1] = M[0] = M[1] = 1;
	for (int i=2; i<101; ++i)
		D[i] = (D[i-2] + D[i-1]) % MOD;
	for (int i=2; i<101; ++i)
		if (i%2 == 0)
			M[i] = (D[i/2] + D[i/2-1]) % MOD;
		else
			M[i] = D[i/2];
	while (C--) {
		cin >> N;
		int ret = D[N] - M[N];
		if (ret <0) ret += MOD;
		cout << ret % MOD << endl;

	}


	return 0;
}


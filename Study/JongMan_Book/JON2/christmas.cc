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
#include <set>
#include <numeric>
using namespace std;

int testNum, N, K, D[100001], pSum[100001];

int Solve (int n) {

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N >> K;

		vector<int> mod(K, 0);

		for (int i=1; i<=N; ++i) {
			scanf("%d", D+i);
			pSum[i] = (D[i] + pSum[i-1]) % K;
			++mod[pSum[i]];
		}
		++mod[pSum[0]];

		long long ans1 = 0;
		for (int i=0; i<K; ++i)
			ans1 = (ans1 + mod[i] * (mod[i] - 1) / 2) % MOD;

		cout << ans1 << " " << Solve(0) << endl;
	}


	return 0;
}


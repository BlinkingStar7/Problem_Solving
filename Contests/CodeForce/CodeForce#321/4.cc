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

long long N, M, K, D[19], Rule[19][19];
long long Memo[1<<18][19];

long long Solve (int cur, int last, int left) {
	if (left == 0) return 0;

	long long &ret = Memo[cur][last];
	if (ret != -1) return ret;

	ret = 0;
	for (int next=1; next<=N; ++next) {
		if (!(cur & (1 << next-1)))
			ret = max (ret, D[next] + Rule[last][next] + Solve(cur | (1<<next-1), next, left-1));
	}
	return ret;
}

int main () {
	cin >> N >> M >> K;
	
	for (int i=1; i<=N; ++i)
		cin >> D[i];

	for (int i=0; i<K; ++i) {
		int f, t, c;
		cin >> f >> t >> c;
		Rule[f][t] = c;
	}

	memset (Memo, -1, sizeof(Memo));

	cout << Solve(0, 0, M) << endl;
	return 0;
}


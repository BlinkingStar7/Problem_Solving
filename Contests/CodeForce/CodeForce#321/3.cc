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

int N, M, C[100001];
vector<int> G[100001];

int Solve (int cur, int par, int met) {
	if (met > M) return 0;
	
	int ret = 0;
	bool flag = 0;
	for (int i=0; i<G[cur].size(); ++i)
		if (G[cur][i] != par) {
			flag = true;
			ret += Solve (G[cur][i], cur, C[G[cur][i]] ? met + 1 : 0);
		}
	if (!flag) //leaf
		return 1;
	return ret;
}

int main () {
	cin >> N >> M;
	for (int i=1; i<=N; ++i)
		scanf("%d", &C[i]);

	for (int i=0; i<N-1; ++i) {
		int f, t;
		scanf("%d %d", &f, &t);
		G[f].push_back(t);
		G[t].push_back(f);
	}

	cout << Solve (1, 0, C[1]) << endl;
	return 0;
}


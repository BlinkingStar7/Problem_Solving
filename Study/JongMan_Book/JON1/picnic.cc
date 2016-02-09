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

int Memo[1<<11], C, N, M;
vector<int> G [11];

int Solve(int chk) {
	if (chk == (1<<N)-1) return 1;

	int &ret = Memo[chk];
	if (ret != -1) return ret;

	ret = 0;

	int s;
	for (s=0; chk & 1<<s; ++s);

	for (int i=0; i<G[s].size(); ++i)
		if ((chk & 1<<G[s][i]) == 0)
			ret += Solve (chk | 1<<s | 1<<G[s][i]);
	return ret;
}

int main () {
	cin >> C;
	
	while (C--) {
		cin >> N >> M;

		for (int i=0; i<11; ++i)
			G[i].clear();

		for (int i=0; i<M; ++i) {
			int f, t;
			scanf("%d %d", &f, &t);
			G[f].push_back(t);
			G[t].push_back(f);
		}

		memset(Memo, -1, sizeof(Memo));
		cout << Solve (0) << endl;
	}


	return 0;
}


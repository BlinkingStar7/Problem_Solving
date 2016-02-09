#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
using namespace std;

const int MAX = 987654321;
int testNum, N, K, M, L, Memo[11][1<<13];
unsigned int Prerequisite[13], Opening[11];

int Solve (int semester, int taken) {
	int &ret = Memo[semester][taken];
	if (ret != -1) return ret;

	ret = MAX;

	if (__builtin_popcount(taken) >= K) return ret = 0;
	if (semester == M) 
		return ret = MAX;

	int canTake = Opening[semester] & ~taken;
	for (int i=0; i<N; ++i)
		if ((canTake & (1<<i)) && ((taken & Prerequisite[i]) != Prerequisite[i]))
			canTake &= ~(1<<i);

	for (int toTake = canTake; toTake; toTake = ((toTake - 1) & canTake)) {
		if (__builtin_popcount(toTake) > L) continue;
		ret = min (ret, 1+Solve(semester+1, taken|toTake));
	}

	return ret = min (ret, Solve(semester+1, taken));
}

int main () {
	cin >> testNum;

	while (testNum--) {
		scanf("%d%d%d%d", &N, &K, &M, &L);
		memset(Prerequisite, 0, sizeof(Prerequisite));
		memset(Opening, 0, sizeof(Opening));
		memset(Memo, -1, sizeof(Memo));

		for (int i=0; i<N; ++i) {
			int num;
			scanf("%d", &num);
			for (int j=0; j<num; ++j) {
				int sub;
				scanf("%d", &sub);
				Prerequisite[i] |= (1<<sub);
			}
		}
		
		for (int i=0; i<M; ++i) {
			int c;
			scanf("%d", &c);
			for (int j=0; j<c; ++j) {
				int sub;
				scanf("%d", &sub);
				Opening[i] |= (1<<sub);
			}
		}

		int ret = Solve(0, 0);
		if (ret > M)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ret << endl;

		
	}


	return 0;
}


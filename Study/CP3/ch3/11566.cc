#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) ;
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int N, x, T, K, P[101], V[101], memo[101][1100][25];

int solve(int cur, int budget, int eaten) {
	if (eaten > 2*N) return -INF;
	if (budget < 0) return -INF;
	if (cur == K) return 0;

	int &ret = memo[cur][budget][eaten];
	if (ret != -1) return ret;

	int v = 0;
	for (int i=0; i<=2; ++i, v+=V[cur]) {
		ret = max(ret, v+solve(cur+1, budget, eaten));
		budget -= P[cur];
		eaten++;
	}

	return ret;
}

int main () {
	while (scanf("%d%d%d%d",&N,&x,&T,&K) && (N||x||T||K)) {
		++N;
		int tip = (N*x+10)/11;
		int budget = N*(x-T) - tip;

		for (int i=0; i<K; ++i) {
			scanf("%d", P+i);
			V[i] = 0;
			for (int j=0; j<N; ++j) {
				int t;
				scanf("%d", &t);
				V[i] += t;
			}
		}
		memset(memo, -1, sizeof(memo));
		printf("%.2lf\n", (double)solve(0, budget, 0)/N);
	}
	return 0;
}



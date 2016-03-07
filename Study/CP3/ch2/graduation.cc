#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int N, K, M, L, pre[20], sem[20], memo[11][1<<12];

int solve (int cur, int taken) {
	if (__builtin_popcount(taken) >= K) return 0;
	if (cur >= M) return INF;

	int &ret = memo[cur][taken];
	if (ret != -1) return ret;

	ret = INF;

	int left = 0;
	for (int i=0; i<N; ++i) 
		if (!(taken & (1<<i)) && (sem[cur] & (1<<i)) && (pre[i] & taken) == pre[i])
			left |= 1<<i;

	for (int next=left; next; next = left & (next - 1)) { if (__builtin_popcount(next) > L) continue;
		ret = min (ret, 1+solve(cur+1, taken | next));
	}
	return ret = min (ret, solve(cur+1, taken));
}


int main () {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d%d%d%d", &N, &K, &M, &L);

		memset(pre, 0, sizeof(pre));
		memset(sem, 0, sizeof(sem));
		memset(memo, -1, sizeof(memo));
		for (int i=0; i<N; ++i) {
			int r;
			scanf("%d", &r);
			for (int j=0; j<r; ++j) {
				int t;
				scanf("%d", &t);
				pre[i] |= 1<<t;
			}
		}
		for (int i=0; i<M; ++i) {
			int c;
			scanf("%d", &c);
			for (int j=0; j<c; ++j) {
				int t;
				scanf("%d", &t);
				sem[i] |= 1<<t;
			}
		}

		int ret = solve(0, 0);
		if (ret >= INF) printf("IMPOSSIBLE\n");
		else printf("%d\n", ret);
	}

	return 0;
}


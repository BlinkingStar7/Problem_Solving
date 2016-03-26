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

int n, m, memo[1001], choice[1001];
vpii adj[1001];

int solve(int cur, bool end) {
	if (cur == 1 && end) return 0;

	int &ret = memo[cur];
	if (ret != -1) return ret;

	for (int i=0; i<adj[cur].size(); ++i) {
		int to = adj[cur][i].first, w = adj[cur][i].second;
		int cand = w + solve(to, true);
		if (cand > ret) {
			ret = cand;
			choice[cur] = to;
		}
	}

	return ret;
}

		
int main () {
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}

	memset(memo, -1, sizeof(memo));
	int ans = solve(1, false);
	printf("%d\n", ans);
	int cur = 1;
	do {
		printf("%d ", cur);
		cur = choice[cur];
	} while (cur != 1);
	printf("1\n");

	return 0;
}



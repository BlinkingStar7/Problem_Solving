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

int n, memo[1000001][2];
vi adj[1000001];

int solve(int cur, int must, int p) {
	int &ret = memo[cur][must];
	if (ret != -1) return ret;

	if (must) {
		ret = 1;
		for (int i=0; i<adj[cur].size(); ++i) {
			int next = adj[cur][i];
			if (next != p) ret += solve(next, 0, cur);
		}
	}
	else {
		ret = solve(cur, 1, p);
		int cand = 0;
		for (int i=0; i<adj[cur].size(); ++i) {
			int next = adj[cur][i];
			if (next != p) cand += solve(next, 1, cur);
		}
		ret = min(ret, cand);
	}
	return ret;
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n-1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(memo, -1, sizeof(memo));
	printf("%d\n", solve(1, 0, 0));

	return 0;
}



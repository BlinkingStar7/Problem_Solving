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

struct edge {
	int a, b, w;
	bool operator < (const edge& rhs) const { return w < rhs.w; }
} edges[1001];

struct dset {
	vi p, r;
	dset (int n) : p(n), r(n, 1) {
		for (int i=0; i<n; ++i)
			p[i] = i;
	}
	int Find(int u) { return u == p[u] ? u : (p[u] = Find(p[u])); }
	void Union (int a, int b) {
		a = Find(a), b = Find(b);
		if (a == b) return;
		if (r[b] > r[a]) swap(a, b);
		p[b] = a;
		if (r[b] == r[a]) ++r[a];
	}
};

int N, M, Q, dist[101][101];
vpii adj[101];

void dfs (int from, int cur, int bef, int maxE) {
	dist[from][cur] = dist[cur][from] = maxE;
	for (int i=0; i<(int)adj[cur].size(); ++i) {
		int next = adj[cur][i].first, w = adj[cur][i].second;
		if (next == bef) continue;
		dfs (from, next, cur, max(maxE, w));
	}
}

int main () {
	int cnt = 1;
	while (scanf("%d%d%d", &N, &M, &Q) != EOF && (N || M || Q)) {
		for (int i=0; i<M; ++i)
			scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].w);

		sort(edges, edges+M);

		for (int i=0; i<=N; ++i) adj[i].clear();
		dset sets(N+1);
		int found = 0;
		for (int i=0; i<M && found < N-1; ++i) {
			int u = edges[i].a, v = edges[i].b, w = edges[i].w;
			if (sets.Find(u) != sets.Find(v)) {
				++found;
				adj[u].push_back(make_pair(v, w)); adj[v].push_back(make_pair(u, w));
				sets.Union(u, v);
			}
		}


		fill_n(&dist[0][0], sizeof(dist)/sizeof(int), INF);

		for (int i=1; i<=N; ++i)
			dfs(i, i, -1, 0);

		if (cnt > 1) puts("");
		printf("Case #%d\n", cnt++);

		for (int i=0; i<Q; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			if (dist[a][b] == INF) printf("no path\n");
			else printf("%d\n", dist[a][b]);
		}
	}

	return 0;
}



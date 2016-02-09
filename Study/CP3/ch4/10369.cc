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

int S, V, pos[501][2];

inline int dist(int a, int b) {
	int x = pos[a][0] - pos[b][0], y = pos[a][1] - pos[b][1];
	return x*x + y*y;
}

struct DisjointSet {
	vi p, rank;
	DisjointSet(int n) : p(n), rank(n, 1) {
		for (int i=0; i<n; ++i)
			p[i] = i;
	}

	int Find(int u) {
		return u == p[u] ? u : (p[u] = Find(p[u]));
	}

	void Union(int a, int b) {
		a = Find(a), b = Find(b);
		if (a == b) return;
		if (rank[b] > rank[a]) swap(a, b);
		p[b] = a;
		if (rank[b] == rank[a]) ++rank[a];
	}
};

int kruscal() {
	int E = V*(V-1)/2;
	DisjointSet sets(V);
	vector<piii> edges(E);

	int cnt=0;
	for (int i=0; i<V; ++i)
		for (int j=i+1; j<V; ++j)
			edges[cnt++] = make_pair(dist(i, j), make_pair(i, j));

	sort(edges.begin(), edges.end());

	int num = V, last = 0;
	for (int i=0; i<E && num > S; ++i) {
		int u = edges[i].second.first, v = edges[i].second.second, w = edges[i].first;
		if (sets.Find(u) != sets.Find(v)) {
			--num;
			last = w;
			sets.Union(u, v);
		}
	}
	return last;
}


int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &S, &V);
		for (int i=0; i<V; ++i)
			scanf("%d%d",&pos[i][0], &pos[i][1]);
	
		printf("%.2lf\n", sqrt(kruscal()));
	}
	return 0;
}



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

int N, M;
pii pos[751];

inline int dist (int a, int b) {
	int x = pos[a].first - pos[b].first, y = pos[a].second - pos[b].second;
	return x*x+y*y;
}

struct DisjointSet {
	vi parent, rank;
	DisjointSet (int n) {
		parent.assign(n, 0);
		rank.assign(n, 1);
		for (int i=0; i<n; ++i)
			parent[i] = i;
	}

	int find(int u) {
		return u == parent[u] ? u : (parent[u] = find(parent[u]));
	}

	void Union (int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (rank[a] < rank[b]) swap(a, b);
		parent[b] = a;
		if (rank[a] == rank[b]) ++rank[a];
	}
};

int kruscal(vector<piii> &edges, DisjointSet &sets, vpii &selected) {
	sort(edges.begin(), edges.end());

	int mstCost = 0;
	for (int i=0; i<edges.size(); ++i) {
		int u = edges[i].second.first, v = edges[i].second.second, w = edges[i].first;
		if (sets.find(u) != sets.find(v)) {
			selected.push_back(pii(u, v));
			sets.Union(u, v);
			mstCost += w;
		}
	}
	return mstCost;
}


int main () {
	int t;
	scanf("%d", &t);
	for (int tt=1; tt<=t; ++tt) {
		if (tt > 1) puts("");

		scanf("%d", &N);
		for (int i=1; i<=N; ++i) {
			scanf("%d%d",&pos[i].first, &pos[i].second);
		}

		vector<piii> edges((N*N-1)/2);
		for (int i=1; i<=N; ++i)
			for (int j=i+1; j<=N; ++j) 
				edges.push_back(make_pair(dist(i, j), make_pair(i, j)));

		DisjointSet sets(N+1);
		scanf("%d", &M);
		for (int i=0; i<M; ++i) {
			int a, b;
			scanf("%d%d", &a,&b);
			sets.Union(a, b);
		}

		vpii selected;
		int ret = kruscal(edges, sets, selected);
		DPRINTF(("mstCost = %d\n", ret));
		if (ret == 0) printf("No new highways need\n");
		else {
			for (int i=0; i<(int)selected.size(); ++i)
				printf("%d %d\n", selected[i].first, selected[i].second);
		}
	}

	return 0;
}



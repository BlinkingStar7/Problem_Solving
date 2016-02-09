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
vector<piii> edges;

struct DisjointSet {
	vi parent, rank;
	DisjointSet (int n) {
		parent.assign(n, 0);
		rank.assign(n, 1);
		for (int i=0; i<n; ++i)
			parent[i] = i;
	}

	int Find (int u) {
		return u == parent[u] ? u : (parent[u] = Find(parent[u]));
	}

	void Union (int a, int b) {
		a = Find(a), b = Find(b);
		if (a == b) return;
		parent[b] = a;
	}
};

int kruscal() {
	sort(edges.begin(), edges.end(), greater<piii>());
	
	int mstCost = 0, found = 0;
	DisjointSet sets(N+1);

	for (int i=0; i<M && found < N; ++i) {
		int u = edges[i].second.first, v = edges[i].second.second, w = edges[i].first;
		if (sets.Find(u) != sets.Find(v)) {
			mstCost += w;
			++found;
			sets.Union(u, v);
		}
	}

	return mstCost;
}

int main () {
	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d", &N, &M);
		edges.clear();
		edges.resize(M);

		int sum = 0;
		for (int i=0; i<M; ++i) {
			scanf("%d%d%d", &edges[i].second.first, &edges[i].second.second, &edges[i].first);
			sum += edges[i].first;
		}

		printf("%d\n", sum - kruscal());
	}

	return 0;
}



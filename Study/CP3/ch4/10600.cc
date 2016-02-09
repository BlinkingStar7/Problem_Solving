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

vector<piii> edges;
struct DisjointSet {
	vi p;
	DisjointSet (int n) : p(n) {
	}

	int Find (int u) {
		return u == p[u] ? u : (p[u] = Find(p[u]));
	}

	void Union (int a, int b) {
		a = Find(a), b = Find(b);
		p[b] = a;
	}
};

int N, M;

int kruskal(vi& selected, int jump) {
	DisjointSet sets(N+1);
	int mstCost = 0, found = 0;

	for (int i=0; i<M && found < N-1; ++i) {
		if (jump == i) continue;
		int u = edges[i].second.first, v = edges[i].second.second, w = edges[i].first;
		if (sets.Find(u) != sets.Find(v)) {
			mstCost += w;
			if (jump == -1) selected.push_back(i);
			++found;
			sets.Union(u, v);
		}
	}

	return found == N-1 ? mstCost : INF;
}


int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &N, &M);
		
		edges.clear();
		edges.resize(M);
		for (int i=0; i<M; ++i) {
			scanf("%d%d%d", &edges[i].second.first, &edges[i].second.second, &edges[i].first);
		}

		sort(edges.begin(), edges.end());
		vi selected;
		int mstCost = kruskal(selected, -1);
		int secondMst = INF;
		for (int i=0; i<(int)selected.size(); ++i) {
			int cand = kruskal(selected, selected[i]);
			if (cand > mstCost)
				secondMst = min(secondMst, cand);
		}

		printf("%d %d\n", mstCost, secondMst);
	}

	return 0;
}



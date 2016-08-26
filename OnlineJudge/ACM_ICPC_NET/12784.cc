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

int T, N, M;
vpii adj[1001];

int Solve(int cur, int par) {
	int ret = 0;
	if (adj[cur].size() == 1 && cur != 1) return INF;
	
	for (int i=0; i<adj[cur].size(); ++i) {
		int next = adj[cur][i].first, w = adj[cur][i].second;
	
		if (next != par)
			ret += min (w, Solve(next, cur));
	}
	return ret;
}


int main () {
	scanf("%d", &T);

	for (int i=0; i<T; ++i) {
		scanf("%d%d", &N, &M);

		for (int j=1; j<=N; ++j)
			adj[j].clear();

		for (int j=0; j<M; ++j) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}

		printf("%d\n", Solve(1, -1));
	}
		
	return 0;
}



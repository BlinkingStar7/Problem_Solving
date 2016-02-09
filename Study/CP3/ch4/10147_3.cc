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

int N, M, dis[751][751];
pii pos[751];
inline int dist (int a, int b) {
	int x = pos[a].first - pos[b].first, y = pos[a].second - pos[b].second;
	return x*x+y*y;
}

int prim (vpii &selected) {
	vi p(N+1, -1), minSize(N+1, INF);
	vb visited(N+1, false);

	p[1] = minSize[1] = 0;
	int mstCost = 0;

	for (int i=0; i<N; ++i) {
		int u = -1;
		for (int j=1; j<=N; ++j) {
			if (!visited[j] && (u == -1 || minSize[u] > minSize[j]))
				u = j;
		}

		if (p[u] != u) selected.push_back(make_pair(p[u], u));
		mstCost += minSize[u];
		visited[u] = true;

		for (int j=1; j<=N; ++j) {
			if (!visited[j] && minSize[j] > dis[u][j]) {
				minSize[j] = dis[u][j];
				p[j] = u;
			}
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

		for (int i=1; i<=N; ++i)
			for (int j=i+1; j<=N; ++j) 
				dis[i][j] = dis[j][i] = dist(i, j);

		scanf("%d", &M);
		for (int i=0; i<M; ++i) {
			int a, b;
			scanf("%d%d", &a,&b);
			dis[a][b] = dis[b][a] = 0;
		}

		vpii selected;
		int ret = prim(selected);
		DPRINTF(("mstCost = %d\n", ret));
		if (ret == 0) printf("No new highways need\n");
		else {
			for (int i=0; i<(int)selected.size(); ++i) {
				int u = selected[i].first, v = selected[i].second;
				if (dis[u][v])
					printf("%d %d\n",u,v);
			}
		}
	}

	return 0;
}



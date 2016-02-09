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
priority_queue<piii, vector<piii>, greater<piii> > pq;
vb visited;
inline int dist (int a, int b) {
	int x = pos[a].first - pos[b].first, y = pos[a].second - pos[b].second;
	return x*x+y*y;
}

void process(int u) {
	visited[u] = true;
	for (int i=1; i<=N; ++i) {
		if (!visited[i]) pq.push(make_pair(dis[u][i], make_pair(u, i)));
	}
}

int prim (vpii &selected) {
	pq = priority_queue <piii, vector<piii>, greater<piii> >();
	visited.assign(N+1, false);

	process(1);
	int mst_cost = 0, found = 1;
	while(!pq.empty() && found < N) {
		piii front = pq.top(); pq.pop();
		int w = front.first, u = front.second.first, v = front.second.second;
		if (!visited[v]) {
			process(v);
			++found;
			mst_cost += w;
			selected.push_back(make_pair(u, v));
		}
	}
	return mst_cost;
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



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

int n, m, color[201];
vi adj[201];

bool dfs(int cur) {
	if (color[cur] == -1) color[cur] = 0;
	bool ret = true;

	for (int i=0; i<(int)adj[cur].size() && ret; ++i) {
		int next = adj[cur][i];
		if (color[next] == -1) {
			color[next] = 1 - color[cur];
			ret = dfs(next) && ret;
		}
		else if (color[next] == color[cur])
			ret = false;
	}
	return ret;
}

bool dfsAll() {
	bool ret = true;
	for (int i=0; i<n && ret; ++i) {
		if (color[i])
			ret = ret && dfs(i);
	}
	return ret;
}

int main () {
	while (scanf("%d", &n) != EOF && n) {
		for (int i=0; i<n; ++i)
			adj[i].clear();
		memset(color, -1, sizeof(color));

		scanf("%d", &m);
		for (int i=0; i<m; ++i) {
			int a, b;
			scanf("%d%d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		if (dfsAll()) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}
	return 0;
}



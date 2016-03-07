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

bool adj[501][501], visited[501];
int n, m;

void dfs(int cur, bool flag) {
	visited[cur] = true;
	for (int next=1; next<=n; ++next) {
		bool edge = flag ? adj[cur][next] : adj[next][cur];
		if (edge && !visited[next]) dfs(next, flag);
	}
}

int main () {
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) {
		int a, b;
		scanf("%d%d", &a,&b);
		adj[a][b] = true;
	}

	int ans = 0;
	for (int i=1; i<=n; ++i) {
		memset(visited, false, sizeof(visited));
		dfs(i, true); dfs(i, false);
		bool temp = true;
		for (int j=1; j<=n; ++j)
			if (!visited[j]) {temp = false; break;}
		if (temp) ++ans;
	}

	printf("%d\n", ans);
	return 0;
}



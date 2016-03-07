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

vi adj[102];
int n, m, counter, visited[102];
bool cover[102][102];

void dfs (int cur, int s) {
	visited[cur] = counter;
	cover[s][cur] = true;
	for (int i=0; i<adj[cur].size(); ++i) {
		int next = adj[cur][i];
		if (visited[next] != counter) dfs(next, s);
	}
}

int main () {
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) {
		int a, b;
		scanf("%d%d", &a,&b);
		adj[a].push_back(b);
	}

	for (int i=1; i<=n; ++i) {
		++counter;
		dfs (i, i);
	}

	for (int i=1; i<=n; ++i) {
		int cnt = 0;
		for (int j=1; j<=n; ++j) {
			if (i == j) continue;
			if (cover[i][j]) ++cnt;
			if (cover[j][i]) ++cnt;
		}
		printf("%d\n", n-1-cnt);
	}

	return 0;
}



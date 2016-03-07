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

vi adj[502];
int n, m, counter, visited[502], num[502];
unsigned int cover[502][502/32 + 1];

void dfs(int cur, int start) {
	visited[cur] = counter;
	cover[start][cur/32] |= 1<<(cur%32);
	for (int i=0; i<adj[cur].size(); ++i) {
		int next = adj[cur][i];
		if (visited[next] != counter)
			dfs(next, start);
	}
}

int main () {
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}

	for (int i=1; i<=n; ++i) {
		++counter;
		dfs(i, i);
	}

	int ans = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (cover[i][j/32] & 1<<(j%32)) {++num[i]; ++num[j];}
		//	if (cover[j][i/32] & 1<<(i%32)) ++num[j];
		}
	}

	for (int i=1; i<=n; ++i)
		if (num[i] == n+1) ++ ans;
	printf("%d\n", ans);
	return 0;
}



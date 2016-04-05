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

int n, m, v[100001];
vi adj[100001];

bool dfs(int cur, int bef) {
	v[cur] = 1;
	bool ret = false;
	for (int i=0; i<adj[cur].size(); ++i) {
		int next = adj[cur][i];
		if (next == bef) continue;
		if (v[next] == 1) ret = true;
		else ret = ret || dfs(next, cur);
	}
	return ret;
}

int main () {
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int ans =0;
	for (int cur=0; cur<n; ++cur) {
		if (v[cur] == 0) {
			if (!dfs(cur, cur)) ++ans;
		}
	}

	printf("%d\n", ans);
	return 0;
}



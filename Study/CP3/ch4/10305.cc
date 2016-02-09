#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
using namespace std;
#define PI 2*acos(0.0)
#define IFN 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif

typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;

vi adj[101];
int n, m;

void dfs(vb& visited, vi& ret, int cur) {
	visited[cur] = true;
	for (int next=0; next<adj[cur].size(); ++next)
		if (!visited[adj[cur][next]])
			dfs(visited, ret, adj[cur][next]);
	ret.push_back(cur);
}

vi dfsAll() {
	vb visited(n+1, false);
	vi ret;
	for (int i=1; i<=n; ++i)
		if (!visited[i])
			dfs(visited, ret, i);
	return ret;
}


int main () {
	while(1) {
		scanf("%d%d",&n, &m);
		if (n == 0 && m == 0) break;
		for (int i=1; i<=n; ++i)
			adj[i].clear();

		for (int i=0; i<m; ++i) {
			int x,y;
			scanf("%d%d",&x,&y);
			adj[x].push_back(y);
		}

		vi ans = dfsAll();
		for (int i=ans.size()-1; i>=0; --i)
			printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}


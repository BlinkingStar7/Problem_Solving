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

const int INF = 1e8;
int testNum, n, q, d[100001], a[1<<19], pos, m[100001];
vector<int> adj[100001];

void dfs(int cur, int depth) {
	m[cur] = pos;
	d[cur] = depth;
	a[pos++] = d[cur];
	for (int i=0; i<adj[cur].size(); ++i) {
		int next = adj[cur][i];
		dfs(next, depth+1);
		a[pos++] = d[cur];
	}
}

int find (int x, int y) {
	if (x > y) swap(x, y);
	int ret = INF;
	while (x < y) {
		if (x%2) ret = min(ret, a[x++]);
		if(!y%2) ret = min(ret, a[y--]);
		x>>=1, y>>=1;
	}
	if (x==y) ret = min(ret, a[x]);
	return ret;
}

int main () {
	scanf("%d", &testNum);

	while (testNum--) {
		scanf("%d%d", &n,&q);
		for (int i=0; i<n; ++i) adj[i].clear();
		fill(a, a+sizeof(a)/sizeof(int), INF);
		for (int i=1; i<n; ++i) {
			int p; scanf("%d", &p);
			adj[p].push_back(i);
		}
		
		int base;
		for (base=1; base<2*n; base<<=1)
			;

		pos = base;
		dfs (0, 0);
		for (int i=base-1; i>0; --i) 
			a[i] = min(a[2*i], a[2*i+1]);

		for (int i=0; i<q; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", d[x] + d[y] - 2*find(m[x], m[y]));
		}
	}
	return 0;
}


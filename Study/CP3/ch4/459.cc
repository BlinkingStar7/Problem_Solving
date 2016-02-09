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

vi adj[27], visited(27, 0);
int V;

void dfs(int u) {
	visited[u] = 1;

	for (int i=0; i<(int)adj[u].size(); ++i) {
		int v = adj[u][i];
		if (!visited[v])
			dfs(v);
	}
}

int dfs_all() {
	int ret = 0;
	for (int i=0; i<V; ++i) {
		if (!visited[i]) {
			++ret;
			dfs(i);
		}
	}
	return ret;
}

int main () {
	int t;
	scanf("%d ", &t);
	for (int test=1; test<=t; ++test) {
		if (test != 1) puts("");
		char ch;
		scanf("%c%*c", &ch);

		V = ch - 'A' + 1;
		for (int i=0; i<27; ++i) adj[i].clear();
		visited.assign(27, 0);
		char input[5];
		while (gets(input) && input[0]) {
			char u = input[0], v = input[1];		
			adj[u-'A'].push_back(v-'A');
			adj[v-'A'].push_back(u-'A');
		}

		printf("%d\n", dfs_all());
	}

	return 0;
}



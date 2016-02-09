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

int N, adj[101][101], path[101];
vb visited;
bool ans[101][101];

void dfs(int cur) {
	visited[cur] = true;
	for (int i=0; i<N; ++i)
		if (!visited[i] && adj[cur][i])
			dfs(i);
}

void dominator() {
	dfs(0);
	vb original = visited;

	for (int i=0; i<N; ++i) {
		int store[101];
		for (int j=0; j<N; ++j) {
			store[j] = adj[i][j];
			adj[i][j] = 0;
		}
		visited.assign(N, false);
		dfs(0);
		for (int j=0; j<N; ++j)
			if ((original[i] && i == j) || original[j] != visited[j]) ans[i][j] = true;
			else ans[i][j] = false;
		for (int j=0; j<N; ++j)
			adj[i][j] = store[j];
	}
}

int main () {
	int t;
	cin >> t;
	for (int cnt=1; cnt<=t; ++cnt) {
		memset(path, 0, sizeof(path));
		visited.assign(101, false);
		scanf("%d", &N);
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				scanf("%d", &adj[i][j]);

		dominator();

		printf("Case %d:\n", cnt);
		for (int i=0; i<N; ++i) {
			putchar('+');
			for (int j=0; j<2*N-1; ++j)
				putchar('-');
			printf("+\n");
			for (int j=0; j<N; ++j)
				printf("|%c",ans[i][j] ? 'Y' : 'N');
			printf("|\n");
		}
		putchar('+');
		for (int j=0; j<2*N-1; ++j)
			putchar('-');
		printf("+\n");
	}


	return 0;
}


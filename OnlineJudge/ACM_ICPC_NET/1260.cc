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

int adj[1001][1001];
int N, M, V;
bool Visited[1001];

void dfs (int v) {
	Visited[v] = true;
	printf("%d ", v);

	for (int i=1; i<=N; ++i)
		if (adj[v][i] && !Visited[i])
			dfs (i);
}

void bfs (int v) {
	queue <int> Q;
	Q.push(v);
	Visited[v] = true;

	while(!Q.empty()) {
		int here = Q.front(); Q.pop();
		printf("%d ", here);

		for (int i=1; i<=N; ++i)
			if (adj[here][i] && !Visited[i]) {
				Visited[i] = true;
				Q.push(i);
			}
	}
}



int main () {
	cin >> N >> M >> V;

	for (int i=0; i<M; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		adj[a][b] = adj[b][a] = 1;
	}

	memset(Visited, 0, sizeof(Visited));
	dfs(V);
	puts("");
	memset(Visited, 0, sizeof(Visited));
	bfs(V);
	puts("");

	return 0;
}


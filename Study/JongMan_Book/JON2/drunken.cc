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

const int INF = 987654321;
int testNum, V, E, T[501], adj[501][501], via[501][501], control[501][501];
bool edge[501][501];

void floyd() {
	for (int i=0; i<=V; ++i)
		adj[i][i] = 0;

	for (int k=1; k<=V; ++k) 
		for (int i=1; i<=V; ++i)
			for (int j=1; j<=V; ++j) {
				int cand = adj[i][k] + adj[k][j];
				if (cand < adj[i][j]) {
					via[i][j] = k;
					adj[i][j] = cand;
				}
			}
}

void reconstruct (int u, int v, vector<int>& path) {
	if (via[u][v] == 0) {
		path.push_back(u);
		if (u != v) path.push_back(v);
	}
	else {
		int w = via[u][v];
		reconstruct (u, w, path);
		path.pop_back();
		reconstruct (w, v, path);
	}
}


int main () {
	cin >> V >> E;
	for (int i=0; i<=V; ++i)
		for (int j=0; j<=V; ++j)
			adj[i][j] = INF;

	for (int i=1; i<=V; ++i)
		scanf("%d", T+i);

	for (int i=0; i<E; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a][b] = adj[b][a] = c;
		edge[a][b] = edge[b][a] = true;
	}

	floyd();



	cin >> testNum;

	for (int i=0; i<testNum; ++i) {
		int s, t;
		scanf("%d %d", &s, &t);

		if (edge[s][t] || s == t)
			printf("%d\n", adj[s][t]);
		else {
			int ans = INF;
			
			for (int k=1; k<=V; ++k) {
				if (k == s || k == t) continue;
				vector<int> path;
				reconstruct (s, k, path);
				path.pop_back();
				reconstruct (k, t, path);
				path.pop_back();
				int x = 0;
				for (int i=1; i<path.size(); ++i) {
					printf(" %d", path[i]);
					x = max (x, T[path[i]]);
				}
				printf(" max : %d\n", x);
				ans = min (ans, adj[s][k] + x + adj[k][t]);
			}
			printf("%d\n", ans);
		}
	}


	return 0;
}


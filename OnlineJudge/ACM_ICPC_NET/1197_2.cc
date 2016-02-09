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

int V, E;
const int INF = 987654321;
vector<pair<int, int> > adj[100001];

long long Prim() {
	long long ret = 0;
	vector<int> Visited(V+1), D(V+1, INF);
	D[1] = 0;

	for (int i=1; i<=V; ++i) {
		int val = INF, n = -1;
		for (int j=1; j<=V; ++j)
			if (!Visited[j] && D[j] < val) {
				val = D[j];
				n = j;
			}
		Visited[n] = 1;
		ret += D[n];
		for (int j=0; j<adj[n].size(); ++j) {
			int there = adj[n][j].second, cost = adj[n][j].first;
			D[there] = min (D[there], cost);
		}
	}

	return ret;
}

				

int main () {
	cin >> V >> E;
	for (int i=0; i<E; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		adj[a].push_back(make_pair(c, b));
		adj[b].push_back(make_pair(c, a));
	}

	printf("%lld\n", Prim());
	
	return 0;
}


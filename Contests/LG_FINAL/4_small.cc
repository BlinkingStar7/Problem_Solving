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
int testNum, V, E, Total[5001];
map<pair<int, int>, int> m;

vector<pair<int, int> > adj[1001];

int prim() {
	vector<bool> added (V, false);
	vector<int> minWeight (V, INF), parent(V, -1);
	int ret = 0;

	minWeight[0] = parent[0] = 0;
	for (int iter = 0; iter < V; ++iter) {
		int u = -1;
		for (int v=0; v<V; ++v)
			if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
				u = v;
		ret += minWeight[u];
		added[u] = true;

		for (int i=0; i<adj[u].size(); ++i) {
			int v = adj[u][i].first, weight = adj[u][i].second;
			if (!added[v] && minWeight[v] > weight) {
				parent[v] = u;
				minWeight[v] = weight;
			}
		}
	}
	return ret;
}

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i=0; i<n; ++i)
			parent[i] = i;
	}

	int find (int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge (int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) ++ rank[v];
	}
};

int kruskal() {
	int ret = 0;
	vector<bool> visited(V, false);
	vector<pair<int, pair<int, int> > > edges;
	for (int u=0; u<V; ++u)
		for (int i = 0; i<adj[u].size(); ++i) {
			int v = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, v)));
		}

	sort (edges.begin(), edges.end());
	DisjointSet sets(V);
	for (int i=0; i<edges.size(); ++i) {
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		int setNum = Total[m[make_pair(u, v)]];
		if (sets.find(u) == sets.find(v) || visited[setNum]) continue;
		sets.merge(u, v);
		visited[setNum] = true;
		ret += cost;
	}
	return ret;
}

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> V >> E;
		m.clear();
		for (int i=0; i<V; ++i)
			adj[i].clear();

		for (int i=0; i<E; ++i) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			m[make_pair(a-1, b-1)] = i+1;
			m[make_pair(b-1, a-1)] = i+1;
			adj[a-1].push_back(make_pair(b-1, c));
			adj[b-1].push_back(make_pair(a-1, c));
		}

		for (int i=0; i<V-1; ++i) {
			int n;
			scanf("%d", &n);
			for (int j=0; j<n; ++j) {
				int x;
				scanf("%d", &x);
				Total[x] = i;
			}
		}

		int shortest = prim();
		int cand = kruskal();
		if (cand == shortest)
			printf("1\n");
		else
			printf("0\n");
	}


	return 0;
}


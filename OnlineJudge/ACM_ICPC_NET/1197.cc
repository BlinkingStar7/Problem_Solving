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

typedef pair<int, pair<int, int> > Edge;

int V, E;
Edge edges[100001];
struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet (int n) : parent(n), rank(n, 1) {
		for (int i=0; i<n; ++i)
			parent[i] = i;
	}

	int findParent (int n) {
		if (parent[n] == n) return n;
		else return parent[n] = findParent (parent[n]);
	}

	void Union (int a, int b) {
		a = findParent(a), b = findParent(b);
		if (a == b) return;
		if (rank[a] > rank[b]) swap(a, b);
		parent[a] = b;
		if (rank[a] == rank[b]) ++rank[b];
	}
};

long long  Kruskal () {
	DisjointSet set(V);
	sort (edges, edges+E);
	long long ret = 0;

	for (int i=0; i<E; ++i) {
		int a = edges[i].second.first-1, b = edges[i].second.second-1, c = edges[i].first;
		if (set.findParent(a) == set.findParent(b)) continue;
		set.Union (a, b);
		ret += c;
	}


	return ret;
}


	
int main () {
	cin >> V >> E;

	for (int i=0; i<E; ++i) {
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		edges[i] = make_pair(c, make_pair(a, b));
	}

	printf("%lld\n", Kruskal());
	return 0;
}


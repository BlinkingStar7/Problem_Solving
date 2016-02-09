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

int testNum, g, h;
vector<int> adj[1001];
bool Colored[1001], Visited[1001];

void init() {
	memset(Colored, 0, sizeof(Colored));
	memset(Visited, 0, sizeof(Visited));
	for (int i=0; i<g; ++i)
		adj[i].clear();
}

int dfs(int parent, int here) {
	int ret = 0;
	Visited[here] = true;
	for (int i=0; i<adj[here].size(); ++i) {
		int there = adj[here][i];
		if (!Visited[there])
			ret += dfs(here, there);
	}
	
	bool childAllColoerd = true;
	for (int i=0; i<adj[here].size(); ++i) {
		int there = adj[here][i];
		if (there != parent && !Colored[there]) {
			childAllColoerd = false;
			break;
		}
	}

	if (!childAllColoerd) {
		++ret;
		for (int i=0; i<adj[here].size(); ++i) {
			int there = adj[here][i];
			Colored[there] = true;
		}
		Colored[here] = true;
	}

	return ret;
}

int dfsAll() {
	int ret = 0;
	for (int i=0; i<g; ++i)
		if (!Visited[i]) 
			ret += dfs(i, i) + (!Colored[i] ? 1 : 0);
	

	return ret;
}

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> g >> h;
		init();
		for (int i=0; i<h; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		cout << dfsAll() << endl;
	}


	return 0;
}


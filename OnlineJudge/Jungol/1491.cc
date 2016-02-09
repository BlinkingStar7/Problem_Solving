#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int L, N, D[123], R[123];
vector<vector<pair<int, int> > > adj;
int cnt;
map<pair<int, int>, int> m;

inline pair<bool, int> getNum (int n, int fuel) {
	pair<int, int> curNode = make_pair (n, fuel);
	return (m.find(curNode) == m.end() ? make_pair(false, (m[curNode] = cnt++)) : make_pair(true,  m[curNode]));
}

void makeNode (int n, int fuel) {
	int cur = getNum (n, fuel).second;

	if (n == N+1) {
		int next = getNum (n+1, 0).second;
		adj[cur].push_back(make_pair(0, next));
		return;
	}

	pair<bool, int> ret;
	if (fuel >= D[n]) {
		ret = getNum (n+1, fuel-D[n]);
		int next = ret.second;
		adj[cur].push_back(make_pair(0, next));
		if (!ret.first) makeNode (n+1, fuel-D[n]);
	}
	ret = getNum (n+1, L);
	int next = ret.second;
	adj[cur].push_back(make_pair(R[n], next));
	if (!ret.first) makeNode (n+1, L);
}

int dijkstra(int src, int dest) {
	vector<int> dist(dest+1, INF);
	vector<bool> visited(dest+1, false);
	priority_queue<int> q;
	q.push(src);
	dist[src] = 0;
	visited

	while(!q.empty()) {
		int cur = q.top(); q.pop();

int main() {
	cin >> L >> N;
	adj.resize(N+3);
	for (int i=0; i<N+1; ++i) 
		scanf("%d", D+i);
	for (int i=0; i<N+1; ++i) 
		scanf("%d", R+i);

	makeNode (0, L);
	
	return 0;
}



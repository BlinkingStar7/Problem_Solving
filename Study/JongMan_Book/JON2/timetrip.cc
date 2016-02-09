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
int testNum, V, W;
vector<pair<int, int> > adj[101];

int bellmanFord (int flag) {
	vector<int> dist(V, INF);
	dist[0] = 0;
	bool updated = false; 
	
	for (int it=0; it<V; ++it) {
		updated = false;
		for (int here=0; here<V; ++here) {
			for (int i=0; i<adj[here].size(); ++i) {
				int there = adj[here][i].second;
				int cost = flag*adj[here][i].first;
				if (dist[here] + cost < dist[there]) {
					updated = true;
					dist[there] = dist[here] + cost;
				}
			}
		}
		if (!updated) break;
	}
	if (updated) return -1;
	return dist[1];
}

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> V >> W;
		for (int i=0; i<V; ++i)
			adj[i].clear();
		
		for (int i=0; i<W; ++i) {
			int a, b, d;
			scanf ("%d %d %d", &a, &b, &d);
			adj[a].push_back(make_pair(d, b));
		}

		int past, future;
		past = bellmanFord(1);
		if (past == -1) cout << "INFINITY";
		else if (past > INF - 123456) {
			cout << "UNREACHABLE" << endl;
			continue;
		}
		else 
			cout << past;

		future = bellmanFord(-1);
		if (future == -1) cout << " INFINITY" << endl;
		else
			cout << " " << -future << endl;
	}


	return 0;
}


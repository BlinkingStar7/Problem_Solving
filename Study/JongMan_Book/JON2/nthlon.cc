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
int testNum, M;
pair<int, int> edge[501];

int Dijkstra () {
	vector<int> dist(401, INF);
	vector<bool> visited(401, false);

	dist[0] = 0;

	while (1) {
		int closest = INF, here;
		for (int i=0; i<401; ++i) 
			if (dist[i] < closest && !visited[i]) {
				closest = dist[i];
				here = i;
			}
		
		if (closest == INF) break;
		visited[here] = true;

		for (int i=0; i<M; ++i) {
			int there = (here==0) ? 200 + edge[i].first : here + edge[i].first;
			if (there < 0 || there > 400 || visited[there]) continue;
			dist[there] = min(dist[there], dist[here] + edge[i].second);
		}
	}
	return dist[200];
}
			
int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> M;

		for (int i=0; i<M; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			edge[i] = make_pair(a-b, a);
		}

		int ret = Dijkstra();
		if (ret == INF) cout << "IMPOSSIBLE" << endl;
		else cout << ret << endl;


	}


	return 0;
}


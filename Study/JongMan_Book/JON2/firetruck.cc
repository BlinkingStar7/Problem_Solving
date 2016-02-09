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
int testNum, V, E, N, M;
vector<pair<int, int> >adj[1001];

vector<int> Dijkstra (int station) {
	vector<int> dist(V, INF);
	priority_queue<pair<int, int> > pq;
	dist[station] = 0;
	pq.push(make_pair(0, station));

	while (!pq.empty()) {
		int here = pq.top().second;
		int d = -pq.top().first;
		pq.pop();

		if (d > dist[here]) continue;

		for (int i=0; i<adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int cand = d + adj[here][i].second;

			if (cand < dist[there]) {
				dist[there] = cand;
				pq.push(make_pair(-cand, there));
			}
		}
	}
	return dist;
}

int main () {
	cin >> testNum;

	while (testNum--) {
		scanf("%d %d %d %d", &V, &E, &N, &M);

		for (int i=0; i<V; ++i)
			adj[i].clear();

		for (int i=0; i<E; ++i) {
			int a, b, t;
			scanf("%d %d %d", &a, &b, &t);
			adj[a-1].push_back(make_pair(b-1, t));
			adj[b-1].push_back(make_pair(a-1, t));
		}

		vector<int> fire(N);
		int station;
		for (int i=0; i<N; ++i)
			scanf("%d", &fire[i]);

		scanf("%d", &station);
		for (int i=0; i<M-1; ++i) {
			int t;
			scanf("%d", &t);
			adj[station-1].push_back(make_pair(t-1, 0));
			adj[t-1].push_back(make_pair(station-1, 0));
		}

		vector<int> dist = Dijkstra(station-1);
		int sum = 0;
		for (int i=0; i<fire.size(); ++i)
			sum += dist[fire[i]-1];
		cout << sum << endl;
	}

	return 0;
}


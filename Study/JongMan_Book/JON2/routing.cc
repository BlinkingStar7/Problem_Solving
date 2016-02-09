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

const double INF = 1e100;
int testNum, N, M;
vector<pair<int, double> > adj[10001];

double Dijkstra () {
	vector<double> dist (N, INF);
	priority_queue <pair<double, int> > pq;
	pq.push(make_pair(0, 0));
	dist[0] = 0;

	while (!pq.empty()) {
		double d = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < d) continue;

		for (int i=0; i<adj[here].size(); ++i) {
			int there = adj[here][i].first;
			double cand = d + adj[here][i].second;

			if (cand < dist[there]) {
				dist[there] = cand;
				pq.push(make_pair(-cand, there));
			}
		}
	}
	return dist[N-1];
}


int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N >> M;
		for (int i=0; i<N; ++i)
			adj[i].clear();

		for (int i=0; i<M; ++i) {
			int a, b;
			double d;
			scanf("%d %d %lf", &a, &b, &d);
			adj[a].push_back(make_pair(b, log10(d)));
			adj[b].push_back(make_pair(a, log10(d)));
		}

		printf("%.10lf\n", pow(10, Dijkstra()));


	}


	return 0;
}


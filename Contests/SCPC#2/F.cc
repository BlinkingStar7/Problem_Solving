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
#define MIN(a, b) ((a)>(b)?(b):(a))

const int MAX = 987654321;
int testNum, V, E;
vector<pair<int, int> > adj[501];
bool Set[501];

vector<int> dijkstar(int src) {

	vector<int> dist(V, MAX);
	dist[src] = 0;
	priority_queue<pair<int, int> >pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i=0; i<adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

int main () {
	cin >> testNum;

	for (int tn=1; tn<=testNum; ++tn) {
		memset(Set, 0, sizeof(Set));
		scanf("%d %d", &V, &E);

		for (int i=0; i<E; ++i) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			adj[a-1].push_back(make_pair(b-1, c));
			adj[b-1].push_back(make_pair(a-1, c));
		}


		int ans[501], cnt=0;
		vector<int> dist[501];

		for (int i=0; i<V; ++i) 
			dist[i] = dijkstar(i);

		for (int i=0; i<V; ++i)
			for (int j=i+1; j<V; ++j) {
				int q=-1;
				for (int k=0; k<V; ++k) {
					if (k == i || k == j) continue;
					if (dist[i][k] + dist[k][j] == dist[i][j]) {
						if (q != -1) {
							q = -1;
							break;
						}
						else q=k;
					}
				}
				if (q!=-1 && !Set[q]) {
					Set[q] = true;
					ans[cnt++] = q;
				}
			}

		sort(ans, ans+cnt);

		printf("Case #%d\n", tn);
		printf("%d", cnt);
		for (int i=0; i<cnt; ++i)
			printf(" %d", ans[i]+1);
		puts("");
	}

	return 0;
}


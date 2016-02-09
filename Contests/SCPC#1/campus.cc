#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <numeric>
using namespace std;

const int INF = 0x7fffffff;
int tN, N, M, A[1001];
vector<pair<int, int> > Graph[1001];

void Dijkstar(int start) {
	vector<bool> visited (N+1, false);
	vector<pair<int, int> > dist (N+1, make_pair(INF, 0));

	dist[start].first = 0;
	int org = A[start];

	for (int count=0; count<N-1; ++count) {
		int min = INF, min_index;
		for (int v=1; v<=N; ++v) {
			if (!visited[v] && dist[v].first <= min)
				min = dist[v].first, min_index = v;
		}
		visited[min_index] = true;
		++A[min_index];
		++A[dist[min_index].second];

		for (int v=0; v<Graph[min_index].size(); ++v) {
			int cand = (Graph[min_index][v]).first, weight = (Graph[min_index][v]).second;
			if (!visited[cand] && dist[min_index].first != INF && dist[min_index].first+weight<dist[cand].first)
				dist[cand] = make_pair(dist[min_index].first+weight, min_index); 
		}
	}
	--A[0];
	A[start] = org;
}
		

int main () {
	setbuf(stdout, NULL);
	cin >> tN;
	for (int t=1; t<=tN; ++t) {
		memset(A, 0, sizeof(A));
		cin >> N >> M;
		for (int i=0; i<=N; ++i)
			Graph[i].clear();

		for (int i=0; i<M; ++i) {
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			Graph[a].push_back(make_pair(b, w));
			Graph[b].push_back(make_pair(a, w));
		}

		for (int base=1; base<=N; ++base)
			Dijkstar(base);

		vector<int> ans;

		for (int i=1; i<=N; ++i)
			if (A[i] <= N) ans.push_back(i);

		printf("Case #%d\n",t);
		printf("%d", ans.size());
		for (int i=0; i<ans.size(); ++i)
			printf(" %d", ans[i]);
		printf("\n");
	}
		
	return 0;
}


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

int N, M, p[1001];
pair <int, pair<int, int> > edge[100001];

int find (int n) {
	return p[n] == n ? n : p[n] = find(p[n]);
}

void merge (int a, int b) {
	p[find(a)] = find(b);
}

int main () {
	cin >> N >> M;
	for (int i=0; i<M; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		edge[i] = make_pair(c, make_pair(a, b));
	}

	sort (edge, edge + M);
	for (int i=1; i<=N; ++i)
		p[i] = i;
	int i=0, num=0, cost=0;
	while (num < N-1) {
		int a = edge[i].second.first, b = edge[i].second.second, c= edge[i].first;
		++i;

		if (find(a) == find(b)) continue;
		merge (a, b);
		++num;
		cost += c;
	}

	printf("%d\n", cost);




	return 0;
}


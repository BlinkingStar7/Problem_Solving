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

const int INF = 98765432;
int V, E, d[1001][1001];

int main () {
	cin >> V >> E;
	for (int i=1; i<=V; ++i)
		for (int j=1; j<=V; ++j)
			if (i == j) continue;
			else d[i][j] = INF;

	for (int i=0; i<E; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		d[a][b] = d[b][a] = min(d[a][b], c);
	}

	for (int k=1; k<=V; ++k)
		for (int i=1; i<=V; ++i) 
			for (int j=1; j<=V; ++j)
				d[i][j] = min (d[i][j], d[i][k] + d[k][j]);

	int a, b;
	cin >> a >> b;
	int cand = min(d[1][a]+d[a][b]+d[b][V], d[1][b] + d[b][a] + d[a][V]);
	if (cand >= INF) cand = -1;
	printf("%d\n", cand);


	return 0;
}


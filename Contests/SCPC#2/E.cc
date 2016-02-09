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

int testNum, V, E, adj[501][501];
const int MAX = 987654321;
bool Set[501];

int main () {
	cin >> testNum;

	for (int tn=1; tn<=testNum; ++tn) {
		memset(Set, 0, sizeof(Set));
		scanf("%d %d", &V, &E);

		for (int i=0; i<V; ++i)
			for (int j=0; j<V; ++j) {
				if (i==j) adj[i][j] = 0;
				else adj[i][j] = MAX;
			}

		for (int i=0; i<E; ++i) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			adj[a-1][b-1] = adj[b-1][a-1] = c;
		}

		for (int k=0; k<V; ++k)
			for (int i=0; i<V; ++i) {
				for (int j=0; j<V; ++j)
					adj[i][j] = MIN(adj[i][j], adj[i][k] + adj[k][j]);
			}

		int ans[501], cnt=0;

		for (int i=0; i<V; ++i)
			for (int j=i+1; j<V; ++j) {
				int q=-1;
				for (int k=0; k<V; ++k) {
					if (k == i || k == j) continue;
					if (adj[i][k] + adj[k][j] == adj[i][j]) {
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


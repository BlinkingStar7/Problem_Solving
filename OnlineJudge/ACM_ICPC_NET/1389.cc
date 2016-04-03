#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) ;
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int n, m, adj[101][101];
int main () {
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j)
		adj[i][j] = i == j ? 0 : INF;

	for (int i=0; i<m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		adj[a][b] = adj[b][a] = 1;
	}


	for (int k=0; k<n; ++k) for (int i=0; i<n; ++i) for (int j=0; j<n; ++j)
		adj[i][j] = min (adj[i][j], adj[i][k] + adj[k][j]);

	int best = INF, ans;
	for (int i=0; i<n; ++i) {
		int sum = 0;
		for (int j=0; j<n; ++j) sum += adj[i][j];
		if (sum < best) {
			best = sum;
			ans = i+1;
		}
	}

	printf("%d\n", ans);
	return 0;
}



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

int n, m, adj[101][101], v[101];

int main () {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i) for (int j=1; j<=n; ++j)
		adj[i][j] = i == j ? 0 : INF;

	for (int i=0; i<m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a][b] = adj[b][a] = 1;
	}

	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	vi ans;
	for (int i=1; i<=n; ++i) {
		if (!v[i]) {
			vi temp;
			for (int j=1; j<=n; ++j) 
				if (adj[i][j] != INF) {
					temp.push_back(j);
					v[j] = true;
				}

			int best = INF, rep;
			for (int ii=0; ii<temp.size(); ++ii) {
				int mmax = -1;
				for (int jj=0; jj<temp.size(); ++jj) 
					if (adj[ii][jj] != INF)
						mmax = max(mmax, adj[temp[ii]][temp[jj]]);

				if (mmax < best) {
					best = mmax;
					rep = temp[ii];
				}
			}
			ans.push_back(rep);
		}
	}
	
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i=0; i<ans.size(); ++i)
		printf("%d\n", ans[i]);

	return 0;
}



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

bool adj[502][502];
int n, m;
int main () {
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a][b] = true;
	}

	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				adj[i][j] =  adj[i][j] || (adj[i][k] && adj[k][j]);

	int ans = 0;
	for (int i=1; i<=n; ++i) {
		int cnt1 = 0, cnt2 = 0;
		for (int j=1; j<=n; ++j) {
			if (i == j) continue;
			if (adj[i][j]) ++cnt1;
			if (adj[j][i]) ++cnt2;
		}
		if (cnt1 + cnt2 == n-1) ++ans;
	}

	printf("%d\n", ans);

	return 0;
}



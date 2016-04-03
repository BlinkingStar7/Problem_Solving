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

int n, k, s;
bool adj[401][401];

int main () {
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; ++i)
		adj[i][i] = true;

	for (int i=0; i<k; ++i) {
		int a, b; scanf("%d%d", &a, &b);
		--a, --b;
		adj[a][b] = true;
	}

	for (int k=0; k<n; ++k) for (int i=0; i<n; ++i) for (int j=0; j<n; ++j)
		adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);

	scanf("%d", &s);
	for (int i=0; i<s; ++i) {
		int a, b;
		scanf("%d%d", &a, &b); --a, --b;
		if (adj[a][b]) printf("-1\n");
		if (adj[b][a]) printf("1\n");
		if (!adj[a][b] && !adj[b][a]) printf("0\n");
	}

	return 0;
}



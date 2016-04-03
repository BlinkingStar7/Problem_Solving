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

bool adj[101][101];
int n;
int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
		scanf("%d", &adj[i][j]);
	}

	for (int k=0; k<n; ++k) for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			printf("%d ", adj[i][j] ? 1 : 0);
		puts("");
}
	return 0;
}



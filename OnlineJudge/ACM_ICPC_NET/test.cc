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

int adj[5][5], n;
int main () {
	scanf("%d", &n);
	for (int i=0; i<5; ++i) for (int j=0; j<5; ++j) adj[i][j] = INF;
	for (int i=0; i<n; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		adj[a][b] = c;
		adj[b][a] = c;
	}
	
	for (int k=0; k<5; ++k) for (int i=0; i<5; ++i) for (int j=0; j<5; ++j)
		adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	for (int i=0; i<5; ++i ){
		for (int j=0; j<5; ++j)
			printf("%d ", adj[i][j]);
		puts("");
	}

	return 0;
}



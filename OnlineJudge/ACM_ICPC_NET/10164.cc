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

int memo[16][16], n, m, k;

int main () {
	scanf("%d%d%d", &n, &m, &k);

	for (int i=0; i<=n; ++i)
		for (int j=0; j<=m; ++j) {
			if (i == 1 || j == 1 || i == 0 || j == 0) memo[i][j] = 1;
			else memo[i][j] = memo[i-1][j] + memo[i][j-1];
		}

	int y = (k-1)/m + 1, x= (k-1)%m + 1;
	if (k == 0) printf("%d\n", memo[n][m]);
	else printf("%d\n", memo[y][x]*memo[n-y+1][m-x+1]);

	return 0;
}



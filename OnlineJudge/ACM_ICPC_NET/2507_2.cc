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

int memo[501][501], n, d[501], s[501], t[501];

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d%d%d", d+i, s+i, t+i);

	memo[0][0] = 1;
	for (int g=0; g<n; ++g) for (int c=0; c<n; ++c) {
		if (g == c && g != n-1) continue;
		if (g > c) {
			for (int k=0; k<g; ++k) if (d[k] + s[k] >= d[g])
				memo[g][c] += memo[k][c];
		}
		else {
			for (int k=0; k<c; ++k) if (t[c] && d[k] + s[c] >= d[c])
				memo[g][c] += memo[g][k];
		}
		memo[g][c] %= 1000;
	}

	printf("%d\n", memo[n-1][n-1]);
	return 0;
}



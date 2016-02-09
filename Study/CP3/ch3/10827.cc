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

int n, psum[200][200];
int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i=1; i<=n; ++i) for (int j=1; j<=n; ++j) {
			scanf("%d", &psum[i][j]);
			psum[i+n][j] = psum[i][j+n] = psum[i+n][j+n] = psum[i][j];
		}

		for (int i=1; i<=2*n; ++i)
			for (int j=1; j<=2*n; ++j)
				psum[i][j] += psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1];

		int ans = -INF;
		for (int i=1; i<=n; ++i) for (int ii=i; ii-i<=n-1; ++ii)
			for (int j=1; j<=n; ++j) for (int jj=j; jj-j<=n-1; ++jj)
				ans = max (ans, psum[ii][jj]-psum[i-1][jj]-psum[ii][j-1]+psum[i-1][j-1]);

		printf("%d\n", ans);
	}

	return 0;
}



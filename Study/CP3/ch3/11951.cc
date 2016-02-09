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

long long psum[101][101];

int main () {
	int t;
	scanf("%d", &t);
	for (int tt=1; tt<=t; ++tt) {
		int r, c, k;
		scanf("%d%d%d", &r, &c, &k);

		for (int i=1; i<=r; ++i)
			for (int j=1; j<=c; ++j)
				scanf("%lld", &psum[i][j]);

		for (int i=1; i<=r; ++i)
			for (int j=1; j<=c; ++j)
				psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];

		long long area = 0, cost = 0;

		for (int i=1; i<=r; ++i) for (int j=1; j<=c; ++j)
			for (int ii=i; ii<=r; ++ii) for (int jj=j; jj<=c; ++jj) {
				long long aa = (ii-i+1)*(jj-j+1), cc = psum[ii][jj] - psum[i-1][jj] - psum[ii][j-1] + psum[i-1][j-1];
				if (cc <= k && (aa > area || (area == aa && cc < cost))) {
					area = aa;
					cost = cc;
				}
			}

		printf("Case #%d: %lld %lld\n", tt, area, cost);
	}
	return 0;
}



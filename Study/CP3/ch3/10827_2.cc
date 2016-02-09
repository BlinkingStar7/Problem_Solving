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

int n, psum[80][80], csum[80];
int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(csum, 0, sizeof(csum));
		for (int i=1; i<=n; ++i) for (int j=1; j<=n; ++j) {
			scanf("%d", &psum[i][j]);
			csum[j] += psum[i][j];
			psum[i][j] += psum[i][j-1];
		}

		for (int j=1; j<=n; ++j)
			csum[j] += csum[j-1];

		int ans = -INF;
		for (int j=1; j<=n; ++j) for (int jj=j; jj<=n; ++jj) {
			vi ori{0, 0, csum[jj] - csum[j-1], csum[n] - (csum[jj] - csum[j-1])}, sum = ori;
			for (int i=1; i<=n; ++i) {
				int a = psum[i][jj] - psum[i][j-1], b = psum[i][n] - a;
				sum[0] += a; sum[1] += b; sum[2] -= a; sum[3] -= b;
				for (int k=0; k<4; ++k) {
					ans = max (ans, sum[k]);
					if (sum[k] < ori[k]) sum[k] = ori[k];
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}



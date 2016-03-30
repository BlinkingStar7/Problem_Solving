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

int n, k, c[201], dp[201][201][21], cnt;
int main () {
	scanf("%d%d",&n,&k);
	int bef = -1;
	for (int i=0; i<n; ++i) {
		int cc; scanf("%d", &cc);
		if (cc != bef) {
			bef = cc;
			c[cnt++] = cc;
		}
	}

	for (int start = 0; start<cnt; ++start) {
		for (int num = 0; num<cnt-start; ++num) {
			int ii=num, jj=start+num, mmin = INF;
			for (int q=1; q<=k; ++q) {
				dp[ii][jj][q] = INF;
				if (ii == jj) 
					dp[ii][jj][q] = c[ii] == q ? 0 : 1;
				else 
					for (int c = ii; c<jj; ++c) 
						dp[ii][jj][q] = min(dp[ii][jj][q], dp[ii][c][q] + dp[c+1][jj][q]);

				mmin = min(mmin, dp[ii][jj][q]);
			}

			for (int qq=1; qq<=k; ++qq)
				dp[ii][jj][qq] = min(dp[ii][jj][qq], mmin+1);
			//printf("[%d,%d] to %d = %d\n", ii, jj, q, dp[ii][jj][q]);
		}
	}
	int ans = INF;
	for (int q=1; q<=k; ++q) ans = min(ans, dp[0][cnt-1][q]);
	printf("%d\n", ans);
	return 0;
}



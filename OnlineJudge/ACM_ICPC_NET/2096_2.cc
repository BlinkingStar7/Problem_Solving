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

int dp[2][2][5];
int main () {
	int n;
	cin >> n;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=3; ++j) {
			int t;
			scanf("%d", &t);
			dp[1][i%2][j] = INF;
			for (int k=-1; k<=1; ++k) {
				if (j+k == 0 || j+k == 4) continue;
				dp[0][i%2][j] = max(dp[0][i%2][j], t+dp[0][(i-1)%2][j+k]);
				dp[1][i%2][j] = min(dp[1][i%2][j], t+dp[1][(i-1)%2][j+k]);
			}
		}

	int mmax = 0, mmin = INF;
	for (int i=1; i<=3; ++i) {
		mmax = max(mmax, dp[0][n%2][i]);
		mmin = min(mmin, dp[1][n%2][i]);
	}
	printf("%d %d\n", mmax, mmin);
	return 0;
}


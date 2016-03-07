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

int n, W[16][16], dp[1<<16][16];
int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
		scanf("%d",&W[i][j]);
		if (!W[i][j]) W[i][j] = INF;
	}

	fill(&dp[0][0], &dp[0][0] + sizeof(dp)/sizeof(int), INF);
	dp[1][0] = 0;
	for (int visit=3; visit < (1<<n); visit += 2) {
		for (int cur=1; cur<n; ++cur) {
			if (visit & 1<<cur) {
				int x = visit & ~(1<<cur);
				for (int bef=0; bef<n; ++bef)
					if (x & 1<<bef)
						dp[visit][cur] = min(dp[visit][cur], dp[x][bef] + W[bef][cur]);
			}
		}
	}

	int ans = INF;
	for (int i=1; i<n; ++i)
		ans = min (ans, dp[(1<<n)-1][i] + W[i][0]);

	printf("%d\n", ans);
	return 0;
}



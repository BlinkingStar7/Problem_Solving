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

int main () {
	int n, m;
	cin >> n >> m;
	int ans = 1, dp[50];
	dp[0] = dp[1] = 1;

	for (int i=2; i<50; ++i)
		dp[i] = dp[i-1] + dp[i-2];

	int bef = 0;
	int t;
	for (int i=0; i<m; ++i) {
		scanf("%d", &t);
		ans *= dp[t-bef-1];
		bef = t;
	}
	printf("%d\n",ans*dp[n-bef]);
	return 0;
}



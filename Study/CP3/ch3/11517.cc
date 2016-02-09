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
	int t;
	cin >> t;
	while (t--) {
		int S, N, coin[101], mmax;
		scanf("%d%d", &S, &N);
		mmax = S;
		for (int i=0; i<N; ++i){
			scanf("%d",coin+i);
			mmax = max(mmax, coin[i]);
		}

		int dp[20001];
		fill(dp, dp+2*mmax, INF);
		dp[0] = 0;

		for (int t=0; t<N; ++t)
			for (int m=2*mmax; m>=coin[t]; --m)
				dp[m] = min(dp[m], 1+dp[m-coin[t]]);

		for (int i=S; ; ++i) 
			if (dp[i] < INF) {
				printf("%d %d\n", i, dp[i]);
				break;
			}
	}
	return 0;
}



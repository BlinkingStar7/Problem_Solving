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

int m, S, A[41], B[41];
int main () {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d%d",&m,&S);
		for (int i=0; i<m; ++i)
			scanf("%d%d", A+i, B+i);
		
		int dp[301][301], ans = INF;
		fill(&dp[0][0], &dp[0][0] + sizeof(dp)/sizeof(int), INF);

		dp[0][0] = 0;
		for (int cur=0; cur<m; ++cur)
			for (int a=A[cur]; a<=S; ++a)
				for (int b=B[cur]; a*a+b*b<=S*S; ++b) {
					dp[a][b] = min(dp[a][b], 1+dp[a-A[cur]][b-B[cur]]);
					if (a*a + b*b == S*S) ans = min (ans, dp[a][b]);
				}

		if (ans >= INF) printf("not possible\n");
		else printf("%d\n", ans);
	}

					
	return 0;
}



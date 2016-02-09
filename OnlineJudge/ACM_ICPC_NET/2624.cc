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

int dp[101][10001];
int main () {
	int t, k, p[101], n[101];
	scanf("%d%d",&t,&k);

	for (int i=0; i<k; ++i)
		scanf("%d%d", p+i, n+i);

	for (int i=0; i<=n[0] && p[0]*i <= 10000; ++i)
		dp[0][i*p[0]] = 1;

	for (int type=1; type<k; ++type) {
		for (int money=0; money<=t; ++money) {
			int &cur = dp[type][money];
			if (money == 0) cur = 1;
			else {
				for (int num=0; num<=n[type] && num*p[type]<=money; ++num)
					cur += dp[type-1][money-num*p[type]];
			}
		}
	}

	printf("%d\n", dp[k-1][t]);

	return 0;
}

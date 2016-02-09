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

#define MAX 30000
long long coin[5] = {1,5,10,25,50}, dp[6][MAX+1];

int main () {
	dp[5][0] = 1;

	for (int t=4; t>=0; --t)
		for (int m=0; m<=MAX; ++m)
			dp[t][m] = dp[t+1][m] + (m >= coin[t] ? dp[t][m-coin[t]] : 0);

	int n;
	while (~scanf("%d", &n)) {
		if (dp[0][n] != 1) printf("There are %lld ways to produce %d cents change.\n", dp[0][n], n);
		else printf("There is only 1 way to produce %d cents change.\n", n);
	}

	return 0;
}



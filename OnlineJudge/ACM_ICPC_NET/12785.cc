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

long long MOD = 1000007;
int main () {
	int x, xx, y , yy;
	scanf("%d%d%d%d", &x, &y, &xx, &yy);

	long long d[201][201] = {};

	for (int i=0; i<201; ++i) for (int j=0; j<201; ++j)
		if (i == 0 || j == 0) d[i][j] = 1;
		else d[i][j] = (d[i-1][j] + d[i][j-1]) % MOD;

	printf("%lld\n", (d[xx-1][yy-1]*d[x-xx][y-yy])%MOD);
	return 0;
}



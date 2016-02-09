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

const int MOD = 1000000003;
int N, K, b[1001][1001];

int main () {
	scanf("%d%d", &N, &K);

	b[0][0] = b[1][0] = b[1][1] = 1;
	for (int n=2; n<=N-1; ++n)
		for (int k=0; k<=n; ++k)
			if (k == 0) b[n][k] = 1;
			else b[n][k] = (b[n-1][k] + b[n-2][k-1]) % MOD;

	printf("%d\n", (b[N-2][K] + (b[N-3][K-1]*2)%MOD)%MOD);
	return 0;
}



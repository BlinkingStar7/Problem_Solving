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

const int MOD = 1000000;
int memo[101][101];
int main () {

	for (int k=1; k<=100; ++k)
		for (int n=0; n<=100; ++n)
			if (k == 1 || n == 0) memo[k][n] = 1;
			else memo[k][n] = (memo[k][n-1] + memo[k-1][n])%MOD;

	int n, k;
	while (scanf("%d%d",&n,&k) && (n||k)) {
		printf("%d\n", memo[k][n]);
	}
	return 0;
}



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

int N, K, M;
long long DP[51][51][51];
int main () {
	for (int m=1; m<=50; ++m)
		for (int k=1; k<=50; ++k)
			for (int n=k; n<=50; ++n) {
				long long &cur = DP[m][k][n];
				if (k == 1) cur = n <= m ? 1 : 0;
				else if (n == k) cur = 1;
				else if (n <= m+1) cur = DP[m][k][n-1] + DP[m][k-1][n-1];
				else cur = DP[m][k][n-1] + DP[m][k-1][n-1] - DP[m][k-1][n-m-1];
			}

	while (~scanf("%d%d%d", &N,&K,&M)) {
		printf("%lld\n", DP[M][K][N]);
	}
	return 0;
}



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

int T, K, memo[101][10001];

int main () {
	scanf("%d%d", &T,&K);

	for (int i=0; i<K; ++i) {
		int p, n;
		scanf("%d%d", &p, &n);
		if (i == 0) {
			for (int m=0; m<=T && m<=n*p; m+=p)
				memo[i][m] = 1;
		}
		else {
			for (int m=0; m<=T; ++m) {
				if (m < p) memo[i][m] = memo[i-1][m];
				else memo[i][m] = memo[i][m-p] + memo[i-1][m]  - (m >= (n+1)*p ? memo[i-1][m-(n+1)*p] : 0);
			}
		}
	}

	printf("%d\n", memo[K-1][T]);
	return 0;
}



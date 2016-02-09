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

int N, x, T, K, P[101], V[101], memo[1100][25];

int main () {
	while (scanf("%d%d%d%d",&N,&x,&T,&K) && (N||x||T||K)) {
		++N;
		int tip = (N*x+10)/11;
		int budget = N*(x-T) - tip;

		for (int i=0; i<K; ++i) {
			scanf("%d", P+i);
			V[i] = 0;
			for (int j=0; j<N; ++j) {
				int t;
				scanf("%d", &t);
				V[i] += t;
			}
		}
		memset(memo, 0, sizeof(memo));
		int ans = 0;

		for (int i=0; i<K; ++i) {
			for (int k=2*N; k>=1; --k) {
				for (int m=P[i]; m<=budget; ++m) {
					int &cur = memo[m][k];
					cur = max (cur, V[i] + memo[m-P[i]][k-1]);
					if (m >= 2*P[i] && k>=2)
						cur = max (cur, 2*V[i] + memo[m-2*P[i]][k-2]);
					ans = max(cur, ans);
				}
			}
		}

		printf("%.2lf\n", (double)ans/N);
	}
	return 0;
}



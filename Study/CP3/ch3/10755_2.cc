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

int t, a, b, c;
long long psum[25][25][25];
int main () {
	scanf("%d", &t);
	for (int tt=1; tt<=t; ++tt) {
		scanf("%d%d%d",&a,&b,&c);
		for (int i=1;i<=a;++i) for (int j=1; j<=b; ++j) for (int k=1; k<=c; ++k) {
			scanf("%lld", &psum[i][j][k]);
			psum[i][j][k] += psum[i-1][j][k] + psum[i][j-1][k] - psum[i-1][j-1][k];
		}

		long long ans = -(1LL<<32);

		for (int i=1; i<=a; ++i) for (int j=1; j<=b; ++j) for (int ii=i; ii<=a; ++ii) for (int jj=j; jj<=b; ++jj) {
			long long sum = 0;
			for (int k=1; k<=c; ++k) {
				sum += psum[ii][jj][k] - psum[i-1][jj][k] - psum[ii][j-1][k] + psum[i-1][j-1][k];
				ans = max(ans, sum);
				if (sum < 0) sum = 0;
			}
		}

		if (tt != 1) puts("");
		printf("%lld\n", ans);
	}

	return 0;
}



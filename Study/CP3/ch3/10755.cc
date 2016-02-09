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

long long psum[21][21][21];

int main () {
	int t;
	scanf("%d", &t);
	for (int tt=1; tt<=t; ++tt) {
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);

		memset(psum, 0, sizeof(psum));
		for (int x=1; x<=a; ++x)
			for (int y=1; y<=b; ++y)
				for (int z=1; z<=c; ++z) {
					long long &here = psum[x][y][z];
					scanf("%lld", &here);
					here += psum[x-1][y][z];
					here += psum[x][y-1][z];
					here += psum[x][y][z-1];

					here -= psum[x-1][y-1][z] + psum[x][y-1][z-1] + psum[x-1][y][z-1];
					here += psum[x-1][y-1][z-1];
				}
		
		long long ans = -(1LL<<32);

		for (int x=1; x<=a; ++x) for (int y=1; y<=b; ++y) for (int z=1; z<=c; ++z)
			for (int xx=x; xx<=a; ++xx) for (int yy=y; yy<=b; ++yy) for (int zz=z; zz<=c; ++zz) {
				long long cand = psum[xx][yy][zz] - psum[x-1][yy][zz] - psum[xx][y-1][zz] - psum[xx][yy][z-1];
				cand += psum[x-1][y-1][zz] + psum[xx][y-1][z-1] + psum[x-1][yy][z-1] - psum[x-1][y-1][z-1];
				ans = max(ans, cand);
			}
		if (tt > 1) puts("");
		printf("%lld\n", ans);
	}

	return 0;
}



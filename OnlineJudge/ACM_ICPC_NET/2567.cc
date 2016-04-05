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

const int di[4] = {0,0,1,-1}, dj[4] = {1,-1,0,0};
int n, b[105][105], ans;

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		++x, ++y;
		for (int ii=y; ii<y+10; ++ii)
			for (int jj=x; jj<x+10; ++jj)
				b[ii][jj] = 1;
	}

	for (int i=1; i<=100; ++i) for (int j=1; j<=100; ++j) if (b[i][j]) {
		int num =0;
		for (int d=0; d<4; ++d) {
			int ii=i+di[d], jj=j+dj[d];
			if (b[ii][jj] == 0) {
				++num;
			}
		}
		if (num == 1) ++ans;
		if (num == 2) ans+=2;
	}
	printf("%d\n", ans);

	return 0;
}



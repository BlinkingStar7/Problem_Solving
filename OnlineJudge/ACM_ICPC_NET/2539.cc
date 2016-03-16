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

int r, c, n, m;
bool a[1048576];

bool cover(int len) {
	int ret = 0;
	for (int i=1; i<=c && ret<=n; ++i)
		if (a[i]) {
			++ret;
			i += len-1;
		}
	return ret <= n;;
}

int main () {
	scanf("%d%d%d%d", &r,&c,&n,&m);
	int maxR = 1;
	for (int i=0; i<m; ++i) {
		int rr, cc;
		scanf("%d%d", &rr, &cc);
		if (rr > maxR) maxR = rr;
		a[cc] = 1;
	}

	int lo = maxR, hi = r;
	while (lo < hi) {
		int mid = (lo + hi)/2;
		if (cover(mid)) hi = mid;
		else lo = mid+1;
	}
	printf("%d\n", hi);
	return 0;
}



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

int main () {
	int n, m, x[10001] = {0}, y[10001] = {0};
	scanf("%d%d", &n, &m);

	for (int i=0; i<m; ++i) {
		int xx, yy; scanf("%d%d", &xx, &yy);
		++x[xx], ++y[yy];
	}

	int numx = 0, numy=0, midx = 0, midy = 0;
	for (int i=1; i<=n; ++i) {
		numx += x[i]; numy += y[i];
		if (!midx && numx > m/2) midx = i;
		if (!midy && numy > m/2) midy = i;
		if (midx && midy) break;
	}

	int ans = 0;
	for (int i=1; i<=n; ++i) 
		ans += abs((i - midx)*x[i]) + abs((i - midy)*y[i]);
	printf("%d\n", ans);

	return 0;
}



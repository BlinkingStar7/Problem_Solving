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
	scanf("%d%d%d%d", &n, &m, &t, &k);
	for (int i=0; i<t; ++i) {
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		x[i] = xx - yy, y[i] = xx + yy;
		d[i][0] = x[i], d[i][1] = y[i];
	}

	sort(x, x+t); sort(y, y+t);

	for (int d=0; d<t; ++d) for (int i=0; i<t; ++i) for (int j=0; j<t; ++j) {
		int cnt = 0,
	return 0;
}



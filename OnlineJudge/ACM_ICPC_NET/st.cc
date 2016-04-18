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

int n, m, st[1<<11][11], a[1<<11];
int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", a+i);
		st[i][0] = a[i];
	}

	for (int j=1; (1<<j)<=n; ++j) {
		for (int i=0; i+(1<<j-1)<n; ++i)
			st[i][j] = min(st[i][j-1], st[i+(1<<j-1)][j-1]);
	}

	scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		int aa, bb;
		scanf("%d%d", &aa, &bb);
		--aa, --bb;
		int k = 31 - __builtin_clz(bb-aa+1);
		printf("%d\n", min(st[aa][k], st[bb-(1<<k)+1][k]));
	}
	
	return 0;
}



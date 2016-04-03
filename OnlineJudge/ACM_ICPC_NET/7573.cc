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

int n, l, m, x[101], y[101], f[101][2], ans;
int main () {
	scanf("%d%d%d",&n,&l,&m);
	for (int i=0; i<m; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		f[i][0] = x[i];
		f[i][1] = y[i];
	}

	sort(x, x+m);
	sort(y, y+m);


	for (int i=0; i<m; ++i) for (int j=0; j<m; ++j) for (int k=1; k<l/2; ++k) {
		int c=0;
		for (int ii=0; ii<m; ++ii)  {
			int xx = f[ii][0], yy = f[ii][1];
			if (xx>=x[i] && xx<=x[i]+k && yy>=y[j] && yy<=y[j]+(l/2-k))
				++c;
		}
		if (c > ans) ans = c;
	}
	printf("%d\n", ans);
			
	return 0;
}



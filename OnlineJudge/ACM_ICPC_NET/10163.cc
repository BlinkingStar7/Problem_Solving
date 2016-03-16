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
	int n, b[1100][1100] = {0}, p[110] = {0};
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		int x,y,h,w; scanf("%d%d%d%d", &x,&y,&w,&h);
		for (int ii=0; ii<h; ++ii) for (int jj=0; jj<w; ++jj) {
			p[b[y+ii][x+jj]] --;
			b[y+ii][x+jj] = i;
			p[i]++;
		}
	}
	for (int i=1; i<=n; ++i)
		printf("%d\n", p[i]);

	return 0;
}



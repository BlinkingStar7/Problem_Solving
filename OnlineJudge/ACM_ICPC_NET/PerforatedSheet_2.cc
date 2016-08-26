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

int n;
long long ww, hh;
long long x[1001], y[1001], w[1001], h[1001], area[1001], xx[1001], yy[1001];
int main () {
	scanf("%d", &n);
	scanf("%lld%lld", &ww, &hh);
	for (int i=0; i<n; ++i)
		scanf("%lld", x+i);
	for (int i=0; i<n; ++i)
		scanf("%lld", y+i);
	for (int i=0; i<n; ++i)
		scanf("%lld", w+i);
	for (int i=0; i<n; ++i)
		scanf("%lld", h+i);

	for (int i=0; i<n; ++i)
		area[i] = w[i]*h[i];
	for (int i=0; i<n; ++i)
		xx[i] = 2*x[i] + w[i];
	for (int i=0; i<n; ++i)
		yy[i] = 2*y[i] + h[i];

	long long cx = ww*hh*ww, cy = ww*hh*hh, s = ww*hh;

	for (int i=0; i<n ;++i) {
		cx -= area[i]*xx[i];
		cy -= area[i]*yy[i];
		s -= area[i];
	}
	
	if (s == 0) printf("NO\n");
	else {
		printf("YES\n");
		printf("%lf %lf\n", cx/(2.0*s), cy/(2.0*s));
	}
	
	return 0;
}



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
	int n, a[100001];
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", a+i);
	int ll=0, rr=n-1, best=2100000000, ans1, ans2;
	while (ll < rr) {
		while (ll + 1 < rr && abs(a[ll] + a[rr-1]) < abs(a[ll] + a[rr]))
			--rr;
		if (best > abs(a[ll]+a[rr])) {
			best = abs(a[ll]+a[rr]);
			ans1 = a[ll], ans2 = a[rr];
		}
		++ll;
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}



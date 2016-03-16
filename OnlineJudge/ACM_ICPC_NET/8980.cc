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

int n, c, m, to[2001], ans;
struct load {
	int f, t, w;
	load () {}
}a[10001];

bool compare (const load &x, const load &y) {
	return x.t != y.t ? x.t < y.t : x.f < y.f;
}

int main () {
	scanf("%d%d%d", &n, &c, &m);
	for (int i=0; i<m; ++i) {
		scanf("%d%d%d", &a[i].f, &a[i].t, &a[i].w);
	}

	sort(a, a+m, compare);

	for (int i=0; i<m; ++i) {
		int x=0;
		for (int j=a[i].f; j<a[i].t; ++j)
			if (to[j] > x) x = to[j];
		int left = c - x;
		int y=min(left, a[i].w);
		for (int j=a[i].f; j<a[i].t; ++j)
			to[j] += y;
		ans += y;
	}

	printf("%d\n", ans);
	return 0;
}



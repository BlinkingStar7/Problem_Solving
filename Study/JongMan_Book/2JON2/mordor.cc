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

int c, n, q;

int find (int (&arr)[1<<18], int a, int b) {
	int ret = -INF;
	while (a < b) {
		if (a%2==1) ret = max(ret, arr[a++]);
		if (b%2==0) ret = max(ret, arr[b--]);
		a>>=1, b>>=1;
	}
	if (a == b) ret = max(ret, arr[a]);
	return ret;
}

int main () {
	scanf("%d", &c);
	while (c--) {
		scanf("%d%d", &n, &q);
		int base, a1[1<<18], a2[1<<18];
		fill (a1, a1+sizeof(a1)/sizeof(int), -INF);
		fill (a2, a2+sizeof(a2)/sizeof(int), -INF);
		for (base = 1; base<n; base<<=1);
		for (int i=base; i<base+n; ++i) {
			int t;
			scanf("%d", &t);
			a1[i] = t, a2[i] = -t;
		}

		for (int i=base-1; i>0; --i) {
			a1[i] = max(a1[2*i], a1[2*i+1]);
			a2[i] = max(a2[2*i], a2[2*i+1]);
		}

		for (int i=0; i<q; ++i) {
			int a, b; scanf("%d%d", &a, &b);
			a += base, b+= base;
			printf("%d\n", find(a1, a,b) + find(a2, a, b));
		}
	}

	return 0;
}



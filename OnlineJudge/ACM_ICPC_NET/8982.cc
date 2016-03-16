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

int n, w, k, water[40001], hole[40001], minu[40001];
int main () {
	scanf("%d", &n);
	scanf("%*d%*d");
	for (int i=0; i<(n-2)/2; ++i) {
		int x, xx, h, hh; scanf("%d%d", &x,&h);
		scanf("%d%d", &xx, &hh);
		for (int i=x; i<xx; ++i)
			water[i] = hh;
	}
	scanf("%d%*d", &w);

	scanf("%d", &k);
	for (int i=0; i<k; ++i) {
		int x; scanf("%d%*d%*d%*d", &x);
		hole[x] = water[x]; 
	}

	int h = INF;
	for (int i=0; i<w; ++i) {
		if (hole[i]) h = hole[i];
		if (h == INF) continue;
		minu[i] = (h = min(water[i], h));
	}

	h = INF;
	for (int i=w-1; i>=0; --i) {
		if (hole[i]) h = hole[i];
		if (h == INF) continue;
		minu[i] = max(minu[i], (h = min(water[i], h)));
	}

	int ans = 0;
	for (int i=0; i<w; ++i)
		ans += water[i] - minu[i];

	printf("%d\n", ans);

	return 0;
}



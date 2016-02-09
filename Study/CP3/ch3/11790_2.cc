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

int n, H[10001], W[10001], lis[10001], lds[10001];
int main () {
	int t;
	cin >> t;
	for (int tt=1; tt<=t; ++tt) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d", H+i);
		for (int i=0; i<n; ++i) scanf("%d", W+i);

		int dec=0, inc=0;
		for (int cur=n-1; cur>=0; --cur) {
			lis[cur] = lds[cur] = W[cur];
			for (int next=cur+1; next<n; ++next)
				if (H[next] > H[cur]) lis[cur] = max(lis[cur], W[cur] + lis[next]);
				else if (H[next] < H[cur]) lds[cur] = max(lds[cur], W[cur] + lds[next]);
			dec = max(dec, lds[cur]);
			inc = max(inc, lis[cur]);
		}

		if (inc >= dec) printf("Case %d. Increasing (%d). Decreasing (%d).\n", tt, inc, dec);
		else printf("Case %d. Decreasing (%d). Increasing (%d).\n", tt, dec, inc);
	}
	return 0;
}



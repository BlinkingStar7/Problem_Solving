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

int n, h, b[100001], t[100001];
int main () {
	scanf("%d%d", &n, &h);
	for (int i=0; i<n; ++i) {
		if (i%2==0) scanf("%d", &b[i/2]);
		else scanf("%d", &t[i/2]);
	}

	sort(b, b+n/2);
	sort(t, t+n/2);

	int best = INF, num = 0;
	for (int i=1; i<=h; ++i) {
		int cand = n/2 - (lower_bound(b, b+n/2, i) - b);
		cand += n/2 - (lower_bound(t, t+n/2, h-i+1) - t);
		if (cand == best) ++num;
		else if (cand < best) {
			best = cand;
			num = 1;
		}
	}

	printf("%d %d\n", best, num);
	return 0;
}



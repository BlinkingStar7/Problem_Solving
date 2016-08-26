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
typedef long long ll;
typedef unsigned long long ull;

bool r[100005], c[100005];
int main () {
	int n, m;
	scanf("%d%d", &n, &m);
	
	ll rr=0, cc= 0, ans = (ll)n*n;

	for (int i=0; i<m; ++i) {
		int y, x;
		scanf("%d%d", &x, &y);
		if (!r[y] && !c[x]) {
			++rr;
			++cc;
			ans -= n*2 - rr - cc + 1;
		}
		else if (r[y] && !c[x]) {
			++cc;
			ans -= n-rr;
		}
		else if (!r[y] && c[x]) {
			++rr;
			ans -= n-cc;
		}
		r[y] = c[x] = true;
		printf("%lld%c", ans, i == m-1 ? '\n' : ' ');
	}
	return 0;
}



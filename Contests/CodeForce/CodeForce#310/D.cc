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

int n, m, ans[200001];
pair<long long, long long> b[200001];
struct s {
	long long first, second;
	int ind;
} a[200001];


bool cmp (const s &a, const s &b) {
	return a.first != b.first ? a.first < b.first : a.second < b.second;
}

int main () {
	scanf("%d%d", &n, &m);
	long long xx, yy;
	scanf("%lld%lld",&xx,&yy);

	for (int i=1; i<n; ++i) {
		long long x, y;
		scanf("%lld%lld", &x, &y);
		a[i-1] = (s){x-yy, y-xx, i-1};
		xx = x, yy = y;
	}

	for (int i=0; i<m; ++i) {
		scanf("%lld", &b[i].first);
		b[i].second = i;
	}
		
	sort(a, a+n-1, cmp);
	sort(b, b+m);

	for (int i=0; i<n-1; ++i) {
		pii left = make_pair(a[i].first, 0), right = make_pair(a[i].second, INF);
		int ll = lower_bound(b, b+m, left)-b, rr = lower_bound(b, b+m, right)-b-1;
		c[i] = (s){ll, rr, a[i].ind};
	}
	sort(c, c+n-1, cmp);

	int cur=0, check = 0;
	for (int i=0; cur<m && i<n-1; ++i, ++cur) {
		if (c[i].first <= cur && cur <= c[i].second)
	}

	if (check != n-1) printf("No\n");
	else {
		printf("Yes\n");
		for (int i=0; i<n-1; ++i)
			printf("%d%c", ans[i], i == n-2 ? '\n' : ' ');
	}
	return 0;
}



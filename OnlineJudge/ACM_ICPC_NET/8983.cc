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

int m, n;
ll l, s[100001];
pair<ll, ll> p[100001];

int main () {
	scanf("%d%d%lld", &m,&n,&l);
	for (int i=0; i<m; ++i)
		scanf("%lld", s+i);
	for (int i=0; i<n; ++i)
		scanf("%lld%lld", &p[i].first, &p[i].second);
	sort(s, s+m);
	sort(p, p+n);

	int cur = 0, ans = 0;
	for (int i=0; i<n; ++i) {
		for (; cur < m-1; ++cur)
			if (abs(p[i].first-s[cur]) < abs(p[i].first-s[cur+1])) break;
		if (l >= abs(p[i].first-s[cur]) + p[i].second)
			++ans;
	}
	printf("%d\n", ans);
	return 0;
}



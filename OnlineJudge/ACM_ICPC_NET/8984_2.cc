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
#define MAX 100001
struct B {int t,d,s; bool operator < (const B& b) const { return t == b.t ? d < b.d : t < b.t; }} bar[MAX];
int N, L, tval[MAX], dval[MAX], tnum, dnum;
long long dp[2][MAX], ans;

int main () {
	scanf("%d%d", &N, &L);
	for (int i=0; i<N; ++i) {
		scanf("%d%d", &bar[i].t, &bar[i].d);
		tval[i] = bar[i].t; dval[i] = bar[i].d;
		bar[i].s = abs(tval[i] - dval[i]) + L;
	}

	sort(tval, tval+N); sort(dval, dval+N);
	tnum = unique(tval, tval+N) - tval;
	dnum = unique(dval, dval+N) - dval;

	for (int i=0; i<N; ++i) {
		bar[i].t = lower_bound(tval, tval+tnum, bar[i].t) - tval;
		bar[i].d = lower_bound(dval, dval+dnum, bar[i].d) - dval;
	}

	sort(bar, bar+N);

	for (int i=0; i<N; ++i) {
		long long v1 = dp[1][bar[i].d] + bar[i].s;
		long long v2 = dp[0][bar[i].t] + bar[i].s;
		dp[0][bar[i].t] = max(dp[0][bar[i].t], v1);
		dp[1][bar[i].d] = max(dp[1][bar[i].d], v2);
		ans = max(ans, max(dp[0][bar[i].t], dp[1][bar[i].d]));
	}
	printf("%lld\n", ans);
	return 0;
}



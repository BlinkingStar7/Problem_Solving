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
struct Bar { int t,d,s; } B[MAX];
int N, L, tval[MAX], dval[MAX];
long long memo[2][MAX];

bool compare(const Bar& a, const Bar& b) { return a.t<b.t || (a.t==b.t&&a.d<b.d);}
int main () {
	scanf("%d%d", &N, &L);
	for (int i=0; i<N; ++i) {
		scanf("%d%d", &B[i].t, &B[i].d);
		tval[i] = B[i].t;
		dval[i] = B[i].d;
		B[i].s = L+abs(B[i].t - B[i].d);
	}

	sort(tval, tval+N);
	sort(dval, dval+N);
	
	for (int i=0; i<N; ++i) {
		B[i].t = lower_bound(tval, tval+N, B[i].t) - tval;
		B[i].d = lower_bound(dval, dval+N, B[i].d) - dval;
	}

	sort(B, B+N, compare);
		
	long long ans = 0;
	for (int i=0; i<N; ++i) {
		long long v1 = memo[1][B[i].d] + B[i].s;
		long long v2 = memo[0][B[i].t] + B[i].s;
		memo[0][B[i].t] = max(memo[0][B[i].t], v1);
		memo[1][B[i].d] = max(memo[1][B[i].d], v2);
		ans = max(ans, max(memo[0][B[i].t], memo[1][B[i].d]));
	}

	printf("%lld\n", ans);
	return 0;
}



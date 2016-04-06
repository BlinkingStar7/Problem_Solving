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

const long long MOD = 1e9;
int n, m, p[100001], s[100001];
long long ans;

struct e {
	int a, b;
	long long w;
	bool operator < (const e& r) const {
		return w > r.w;
	}
} e[100001];

int f(int a) {
	return p[a] = (p[a] == a) ? a : f(p[a]);
}

void merge (int a, int b) {
	a = f(a), b = f(b);
	if (a == b) return;
	p[b] = a;
	s[a] += s[b];
}
int main () {
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) 
		scanf("%d%d%lld",&e[i].a,&e[i].b,&e[i].w);
	sort(e, e+m);

	for (int i=1; i<=n; ++i) {
		p[i] = i;
		s[i] = 1;
	}

	long long mul = 0;
	for (int i=0; i<m; ++i) {
		int a = f(e[i].a), b = f(e[i].b);
		long long w = e[i].w;
		if (a != b) {
			mul += (long long)s[a] * s[b];
			merge(a, b);
		}
		ans = (ans + mul*w) % MOD;
	}

	printf("%lld\n", ans);

	return 0;
}



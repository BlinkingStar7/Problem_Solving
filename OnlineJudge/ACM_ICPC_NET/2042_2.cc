#include <bits/stdc++.h>
using namespace std;
#define MID(a, b) (((a)+(b))/2)

long long st[4000001], d[4000001];
int n, m, k;
long long init(int a, int b, int n) {
	return st[n] = (a == b ? d[a] : init(a, MID(a, b), 2*n) + init(MID(a, b)+1, b, 2*n+1));
}

long long u(int l, int r, int p, int v, int n) {
	if (r < p || l > p) return st[n];
	if (l == r) return st[n] = v;
	return st[n] = u(l, MID(l, r), p, v, 2*n) + u(MID(l, r)+1, r, p, v, 2*n+1);
}

long long q(int l, int r, int ll, int rr, int n) {
	if (r < ll || l > rr) return 0;
	if (l >= ll && r <= rr) return st[n];
	return q(l, MID(l, r), ll, rr, 2*n) + q(MID(l, r)+1, r, ll, rr, 2*n+1);
}

int main () {
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0; i<n; ++i) scanf("%lld", d+i);
	init(0, n-1, 1);

	for (int i=0; i<m+k; ++i) {
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		if (a == 1) u(0, n-1, b-1, c, 1);
		else printf("%lld\n", q(0, n-1, b-1, c-1, 1));
	}

	return 0;
}



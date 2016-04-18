#include <bits/stdc++.h>
using namespace std;

long long st[4048567];
int n, m, k, base;
void update (int p, long long v) {
	while (p) {
		st[p] += v;
		p >>= 1;
	}
}

long long query(int a, int b) {
	long long ret = 0;
	while (a < b) {
		if (a%2 == 1) ret += st[a++];
		if (b%2 == 0) ret += st[b--];
		a>>=1, b>>=1;
	}
	if (a == b) ret += st[a];
	return ret;
}

int main () {
	scanf("%d%d%d", &n, &m, &k);
	for (base=1; base<n; base<<=1) ;
	for (int i=0; i<n; ++i)
		scanf("%lld", st+base+i);

	for (int i=base-1; i>0; --i)
		st[i] = st[2*i] + st[2*i+1];

	for (int i=0; i<m+k; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1) update(base+b-1, c-st[base+b-1]);
		else printf("%lld\n", query(base+b-1, base+c-1));
	}

	return 0;
}



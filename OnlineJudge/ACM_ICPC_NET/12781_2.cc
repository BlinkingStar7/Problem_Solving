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

ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

int main () {
	ll x[4], y[4], a[2], b[2], c[2];

	for (int i=0; i<4; ++i)
		scanf("%lld %lld", x+i, y+i);

	for (int i=0; i<2; ++i) {
		a[i] = x[2*i+1]-x[2*i];
		b[i] = -(y[2*i+1]-y[2*i]);
		c[i] = x[2*i]*(y[2*i+1]-y[2*i]) - y[2*i]*(x[2*i+1]-x[2*i]);
	}

	if (a[0] && a[1]) {
		ll lcd = a[0]*a[1]/gcd(a[0], a[1]);
		ll d[2] = {lcd/a[0], lcd/a[1]};
		ll up = d[0]*c[0] - d[1]*c[1], down = -d[0]*b[0] + d[1]*b[1];

		printf("%d\n", (down*x[0] < up) && (up < down*x[1]) ? 1 : 0);
	}
	else if (a[0] == 0) {
		ll up = -c[0], down = b[0];



	return 0;
}



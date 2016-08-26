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

int main () {
	ll n;
	scanf("%lld", &n);
	if (n == 1 || n == 2) { printf("-1\n"); }
	else if (n == 4) {
		printf("3 5\n");
	}
	else {
		ll m, k;
		n *= n;
		if (n%2) {
			m = (1+n)/2;
			k = m-1;
		}
		else {
			m = (2 + (n/2))/2;
			k = m-2;
		}
		printf("%lld %lld\n", m, k);
	}
		return 0;
}



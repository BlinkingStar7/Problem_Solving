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

long long n, k;
long long val(long long v) {
	long long ret = 0;
	for (int i=1; i<=n; ++i)
		ret += min(v/i, n);
	return ret;
}

int main () {
	scanf("%lld%lld", &n, &k);
	long long lo = 0, hi = n*n;
	while (lo < hi) {
		long long mid = lo + (hi-lo)/2;
		if (val(mid) >= k) hi = mid;
		else lo = mid+1;
	}
	printf("%lld\n", hi);
	return 0;
}



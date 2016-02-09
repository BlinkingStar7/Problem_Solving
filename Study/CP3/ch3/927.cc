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

int main () {
	long long t;
	cin >> t;
	while (t--) {
		long long n, d, k;
		cin >> n;
		vi coef(n+1);
		for (long long i=0; i<=n; ++i)
			cin >> coef[i];
		cin >> d >> k;

		long long group=0, x=0;
		while (x < k) {
			++group;
			x += group*d;
		}

		long long nn=1, ans=0;
		for (long long i=0; i<coef.size(); ++i) {
			ans += nn*coef[i];
			nn *= group;
		}
		printf("%lld\n", ans);
	}
		
	return 0;
}



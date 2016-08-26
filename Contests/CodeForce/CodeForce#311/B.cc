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

int n, w;
long long a[200001];
int main () {
	scanf("%d%d", &n, &w);
	for (int i=0; i<2*n; ++i)
		scanf("%lld", a+i);

	sort(a, a+2*n);
	long long x  = *min_element(a, a+n);
	long long xx = *min_element(a+n, a+2*n);

	long long cand = min(2*x, xx);
	printf("%lf\n", min((double)w, (double)3*n*cand/2));
	return 0;
}



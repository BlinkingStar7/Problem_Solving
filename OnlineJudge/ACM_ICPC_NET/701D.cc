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
	ll n, l, v1, v2, k;
	scanf("%lld%lld%lld%lld%lld", &n, &l, &v1, &v2, &k);

	int group = (n-1)/k + 1;

	printf("%.10lf\n", ((double)(2*group*l)/(v2-v1) - (double)l/v2)/(1+(double)2*group*v1/(v2-v1)));

	return 0;
}



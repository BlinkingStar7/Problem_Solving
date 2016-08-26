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

int n, m, a[500001];
int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", a+i);
	sort(a, a+n);
	scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		int t;
		scanf("%d", &t);
		printf("%d ", upper_bound(a, a+n, t) - lower_bound(a, a+n, t));
	}

	return 0;
}



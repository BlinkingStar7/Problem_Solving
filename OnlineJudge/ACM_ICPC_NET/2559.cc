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
	int n, k, a[100001];
	scanf("%d%d", &n, &k);
	int sum = 0, best = -INF;
	for (int i=0; i<k; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}

	best = sum;

	for (int i=k; i<n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i] - a[i-k];
		best = max(best, sum);
	}

	printf("%d\n", best);
	return 0;
}



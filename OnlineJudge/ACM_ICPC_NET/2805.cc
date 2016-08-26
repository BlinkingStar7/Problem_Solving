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

int n, a[1000001];
long long m;
int main () {
	scanf("%d%lld", &n, &m);
	for (int i=0; i<n; ++i)
		scanf("%d", a+i);

	int lo = 0, hi = 2000000000;
	while (lo < hi) {
		int mid = lo + (hi-lo+1)/2;
		long long sum = 0;
		for (int i=0; i<n; ++i)
			sum += max(a[i] - mid, 0);
		if (sum < m) hi = mid-1;
		else lo = mid;
	}

	printf("%d\n", hi);
	return 0;
}



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

int n, m, t[100001];
int main () {
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i)
		scanf("%d", t+i);

	long long lo = 0, hi = (long long)m * 1e9 + 1;

	while (lo < hi) {
		long long mid = (lo+hi)/2, num=0;
		for (int i=0; i<n; ++i)
			num += mid/t[i];
		if (num >= m) hi = mid;
		else lo = mid+1;
	}

	printf("%lld\n", hi);
	return 0;
}



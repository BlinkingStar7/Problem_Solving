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

int n, m, a[300001];
int main () {
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i)
		scanf("%d", a+i);

	int lo=0, hi=1e9;
	while (lo<hi) {
		int mid=(lo+hi)>>1, num=0;
		for (int i=0; i<m; ++i)
			num += (a[i]-1)/mid+1;
		if (num <= n) hi = mid;
		else lo = mid+1;
	}

	printf("%d\n", hi);

	return 0;
}



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
	int n, b, a[1001];
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);
	scanf("%d", &b);

	int lo=0, hi = 1000000000;
	while (lo < hi) {
		int mid = (lo+hi)/2;
		long long sum = 0;
		for (int i=0; i<n; ++i)
			sum += a[i] > mid ? mid : a[i];
		if (sum > b) hi = mid;
		else lo = mid+1;
	}

	int maxelement = *max_element(a, a+n);
	printf("%d\n", min(maxelement, lo-1));

	return 0;
}



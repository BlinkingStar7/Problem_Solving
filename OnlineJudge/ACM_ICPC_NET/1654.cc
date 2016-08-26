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

int n, k, a[10001];
int main () {
	scanf("%d%d", &k, &n);
	for (int i=0; i<k; ++i)
		scanf("%d", a+i);

	int lo = 1, hi = (1LL<<31) - 1;
	while (lo < hi) {
		int mid = lo + (hi-lo+1)/2; // 여기서 오류!~
		long long num = 0;
		for (int i=0; i<k; ++i) {
			num += a[i]/mid;
			if (num >= n) break;
		}
		if (num >= n) lo = mid;
		else hi = mid-1;
	}

	printf("%d\n", hi);

	return 0;
}



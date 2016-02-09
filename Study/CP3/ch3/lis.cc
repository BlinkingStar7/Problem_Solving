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
	int n;
	scanf("%d", &n);
	int lis[501], size = 0, t;
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		int* it = lower_bound(lis, lis+size, t);
		*it = t;
		if (it == lis+size) ++size;
	}
	printf("%d\n", size);
	return 0;
}



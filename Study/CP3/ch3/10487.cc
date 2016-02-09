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
	int n, m, t=1;
	while (scanf("%d", &n) && n) {
		int A[1001];
		for (int i=0; i<n; ++i)
			scanf("%d", A+i);
		scanf("%d", &m);

		printf("Case %d:\n", t++);
		for (int i=0; i<m; ++i) {
			int target; scanf("%d", &target);
			int ans = -INF;
			for (int a=0; a<n; ++a) for (int b=0; b<n; ++b)
				if (a == b) continue;
				else if (abs(A[a]+A[b] - target) < abs(ans-target))
					ans = A[a]+A[b];
			printf("Closest sum to %d is %d.\n", target, ans);
		}
	}

	return 0;
}



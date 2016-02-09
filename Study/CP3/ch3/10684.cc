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
	int n, A[10001];
	while (scanf("%d", &n) && n) {
		for (int i=0; i<n; ++i) scanf("%d", A+i);

		int sum = 0, ans = -INF;
		for (int i=0; i<n; ++i) {
			sum += A[i];
			ans = max(sum, ans);
			if (sum < 0) sum = 0;
		}

		if (ans > 0) printf("The maximum winning streak is %d.\n", ans);
		else printf("Losing streak.\n");
	}
	return 0;
}



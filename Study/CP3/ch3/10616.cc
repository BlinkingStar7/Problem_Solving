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

int n,q,d, memo[201][11][21], A[201];

int solve(int cur, int left, int r) {
	if (left == 0) return r == 0 ? 1 : 0;
	if (cur == n) return 0;

	int &ret = memo[cur][left][r];
	if (ret != -1) return ret;

	ret = 0;
	return ret = solve(cur+1, left-1, (r+A[cur]%d+d)%d) + solve(cur+1, left, r);
}

int main () {
	int cnt = 1;
	while (scanf("%d%d", &n, &q) && (n || q)) {
		printf("SET %d:\n", cnt++);
		for (int i=0; i<n; ++i) scanf("%d", A+i);
		for (int i=0; i<q; ++i) {
			int m;
			scanf("%d%d",&d,&m);
			memset(memo, -1, sizeof(memo));
			printf("QUERY %d: %d\n", i+1, solve(0, m, 0));
		}
	}
	return 0;
}



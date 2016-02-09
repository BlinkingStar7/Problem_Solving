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

int N, cost[101];
int M, mem[101], memo[101][10001];

int solve(int cur, int left) {
	int &ret = memo[cur+1][left];
	if (ret != -1) return ret;

	left -= (cur == -1 ? 0 : cost[cur]);
	ret = (cur == -1 ? 0 : mem[cur]);

	for (int next=cur+1; next<N; ++next)
		if (left >= cost[next])
			ret = max(ret, (cur == -1 ? 0 : mem[cur]) + solve(next, left));
	return ret;
}

int main () {
	scanf("%d%d", &N,&M);
	for (int i=0; i<N; ++i) scanf("%d", mem+i);
	for (int i=0; i<N; ++i) scanf("%d", cost+i);

	int lo = 0, hi = 10001;
	memset(memo, -1, sizeof(memo));
	while (lo < hi) {
		int mid = (lo + hi)/2;
		if (solve(-1, mid) >= M) hi = mid;
		else lo = mid+1;
	}

	printf("%d\n", hi);
	return 0;
}



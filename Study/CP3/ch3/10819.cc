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

int money, n, P[101], V[101], memo[101][10201];

int solve(int cur, int spent) {
	if (cur == n) {
		if (spent > 2000) return spent <= money + 200 ? 0 : -INF;
		else return spent <= money ? 0 : -INF;
	}
	if (spent > money + 200) return -INF;

	int &ret = memo[cur][spent];
	if (ret != -1) return ret;

	return ret = max(solve(cur+1, spent), V[cur] + solve(cur+1, spent+P[cur]));
}
int main () {
	while (scanf("%d%d", &money, &n) != EOF) {
		for (int i=0; i<n; ++i) scanf("%d%d", P+i, V+i);
		memset(memo, -1, sizeof(memo));
		printf("%d\n", solve(0, 0));
	}
	return 0;
}



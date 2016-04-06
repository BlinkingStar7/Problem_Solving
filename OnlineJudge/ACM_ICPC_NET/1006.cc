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

int v[10001][2], w, memo[10001][2][2][2][2], n, t;

int solve(int cur, int a, int b, int aEnd, int bEnd) {
	if (cur == n)
		return a == aEnd && b == bEnd ? 0 : INF;

	int &ret = memo[cur][a][b][aEnd][bEnd];
	if (ret != -1) return ret;

	int x = cur%n, xx = (cur+1)%n;

	ret = INF;
	if (a == 0 && b == 0) {
		ret = min(ret, solve(cur+1, 0, 0, aEnd, bEnd) + (v[x][0] + v[x][1] <= w ? 1 : 2));
		if (v[x][0] + v[xx][0] <= w)
			ret = min(ret, solve(cur+1, 1, 0, aEnd, bEnd) + 2);
		if (v[x][1] + v[xx][1] <= w)
			ret = min(ret, solve(cur+1, 0, 1, aEnd, bEnd) + 2);
		if (v[x][0] + v[xx][0] <= w && v[x][1] + v[xx][1] <= w)
			ret = min(ret, solve(cur+2, 0, 0, aEnd, bEnd) + 2);
	}
	else if (a == 1 && b == 0) {
		ret = min(solve(cur+1, 0, 0, aEnd, bEnd) + 1, ret);
		if (v[x][1] + v[xx][1] <= w)
			ret = min(solve(cur+1, 0, 1, aEnd, bEnd) + 1, ret);
	}
	else if (a == 0 && b == 1) {
		ret = min(solve(cur+1, 0, 0, aEnd, bEnd) + 1, ret);
		if (v[x][0] + v[xx][0] <= w)
			ret = min(solve(cur+1, 1, 0, aEnd, bEnd) + 1, ret);
	}

	return ret;
}

int main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &w);
		for (int i=0; i<2; ++i) for (int j=0; j<n; ++j)
			scanf("%d", &v[j][i]);

		memset(memo, -1, sizeof(memo));
		int ans = min(solve(0, 0, 0, 0, 0), min(solve(0, 1, 0, 1, 0), solve(0, 0, 1, 0, 1)));
		ans = min(ans, solve(1, 0, 0, 1, 1));
		printf("%d\n", ans);
	}

	return 0;
}



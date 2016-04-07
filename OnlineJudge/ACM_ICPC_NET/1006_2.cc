#include <bits/stdc++.h>
using namespace std;
#define INF 1e8

int v[10001][2], w, n, t, memo[10001][3][4]; 

int solve(int cur, int s, int e) {
	if (e != 'd' && cur == n) return e == s ? 0 : INF;
	if (e == 'd' && cur == n+1) return s == 'a' ? 0 : INF;

	int &ret = memo[cur][s-'a'][e-'a'];
	if (ret != -1) return ret;

	ret = INF;
	int x = cur % n, xx = (cur+1) % n;
	if (s == 'a') {
		int cand = min(solve(cur, 'b', e) + 1, solve(cur, 'c', e) + 1);
		if (v[x][0] + v[x][1] <= w) 
			cand = min(solve(cur+1, 'a', e) + 1, cand);
		if (v[x][0] + v[xx][0] <= w && v[x][1] + v[xx][1] <= w)
			cand = min(solve(cur+2, 'a', e) + 2, cand);
		ret = min(ret, cand);
	}
	else if (s == 'b') {
		ret = min(ret, solve(cur+1, 'a', e) + 1);
		if (v[x][1] + v[xx][1] <= w) ret = min(ret, solve(cur+1, 'c', e) + 1);
	}
	else {
		ret = min(ret, solve(cur+1, 'a', e) + 1);
		if (v[x][0] + v[xx][0] <= w) ret = min(ret, solve(cur+1, 'b', e) + 1);
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
		int ans = solve(1, 'a', 'd');
		for (int i=0; i<3; ++i)
			ans = min(ans, solve(0, 'a'+i, 'a'+i));
		printf("%d\n", ans);
	}

	return 0;
}



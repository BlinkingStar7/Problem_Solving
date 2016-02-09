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
#define MAX_N 1000

int memo[MAX_N], h[MAX_N], w[MAX_N], n;

int solve(int cur, int alpha) {
	if (cur == 0) return w[cur];

	int &ret = memo[cur];
	if (ret != -1) return ret;

	ret = w[cur];
	for (int bef = cur-1; bef >= 0; --bef)
		if (cur == n || alpha*h[bef] < alpha*h[cur])
			ret = max(ret, w[cur] + solve(bef, alpha));

	return ret;
}

int main () {
	int t;
	cin >> t;
	for (int tt=1; tt<=t; ++tt) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d",h+i);
		for (int i=0; i<n; ++i) scanf("%d",w+i);

		h[n] = w[n] = 0;
		memset(memo, -1, sizeof(memo));
		int inc = solve(n, 1); 
		for (int i=0; i<n; ++i)
			DPRINTF(("%d ", memo[i]));
		memset(memo, -1, sizeof(memo));
		int dec = solve(n, -1);

		for (int i=0; i<n; ++i)
			DPRINTF(("%d ", memo[i]));
		if (inc >= dec) printf("Case %d. Increasing (%d). Decreasing (%d).\n", tt, inc, dec);
		else printf("Case %d. Decreasing (%d). Increasing (%d).\n", tt, dec, inc);
	}

	return 0;
}



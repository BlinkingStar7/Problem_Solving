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

int memo[501][501], n, d[501], s[501], t[501];
int solve(int go, int come) {
	int &ret = memo[go][come];
	if (ret != -1) return ret;

	ret = (d[go] + s[go] >= d[n-1] && d[come] + s[n-1] >= d[n-1]) ? 1 : 0;

	for (int next = max(go, come)+1; next<n-1; ++next) {
		if (d[go] + s[go] >= d[next]) ret = (ret + solve(next, come)) % 1000;
		if (t[next] && d[come] + s[next] >= d[next]) ret = (ret + solve(go, next)) % 1000;
	}

	return ret;
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d%d%d", d+i, s+i, t+i);

	memset(memo, -1, sizeof(memo));
	printf("%d\n", solve(0, 0));
	return 0;
}



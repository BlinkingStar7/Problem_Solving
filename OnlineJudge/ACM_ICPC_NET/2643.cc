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

int n, memo[101];
pii p[101];

int solve(int cur) {

	int &ret = memo[cur];
	if (ret != -1) return ret;

	ret = 1;
	for (int next=1; next<=n; ++next) {
		if (next == cur) continue;
		if ((p[next].first <= p[cur].first && p[next].second <= p[cur].second) ||
			(p[next].second <= p[cur].first && p[next].first <= p[cur].second))
			ret = max(ret, 1 + solve(next));
	}
	return ret;
}

int main () {
	cin >> n;
	p[0] = make_pair(INF, INF);
	for (int i=1; i<=n; ++i) scanf("%d%d",&p[i].first, &p[i].second);

	memset(memo, -1, sizeof(memo));
	printf("%d\n", solve(0)-1);
	return 0;
}



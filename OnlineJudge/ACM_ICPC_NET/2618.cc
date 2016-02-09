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

int n, w, memo[1002][1002];
pii pos[1002];
inline int dist(int a, int b) {
	return abs(pos[a].first - pos[b].first) + abs(pos[a].second - pos[b].second);
}

int solve(int a, int b) {
	int cur;
	if (b == w+1) cur = a+1;
	else cur=max(a, b)+1;
	if (cur == w+1) return 0;

	int &ret = memo[a][b];
	if (ret != -1) return ret;

	return ret = min(dist(a, cur) + solve(cur, b), dist(b, cur) + solve(a, cur));
}

void recons(vi &ans, int a, int b) {
	int cur;
	if (b == w+1) cur = a+1;
	else cur=max(a, b)+1;

	if (cur == w+1) return;
	if (dist(a, cur) + solve(cur, b) < dist(b, cur) + solve(a, cur)) {
		ans.push_back(1);
		return recons(ans, cur, b);
	}
	else {
		ans.push_back(2);
		return recons(ans, a, cur);
	}
}

int main () {
	scanf("%d%d",&n,&w);
	for (int i=1; i<=w; ++i)
		scanf("%d%d", &pos[i].first, &pos[i].second);
	pos[0] = make_pair(1, 1);
	pos[w+1] = make_pair(n, n);

	memset(memo, -1, sizeof(memo));

	vi ans;
	printf("%d\n", solve(0, w+1));
	recons(ans, 0, w+1);
	for (int i=0; i<ans.size(); ++i)
		printf("%d\n", ans[i]);
	return 0;
}



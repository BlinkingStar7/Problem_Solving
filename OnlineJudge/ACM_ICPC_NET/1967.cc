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

vpii adj[10001];
int n, ans;

int solve(int cur) {
	int b1=0, b2=0;
	for (int i=0; i<adj[cur].size(); ++i) {
		int next = adj[cur][i].first, len = adj[cur][i].second;
		int cand = solve(next) + len;
		if (cand > b1) { b2 = b1; b1 = cand; }
		else if (cand > b2) { b2 = cand; }
	}
	ans = max (ans, b1+b2);
	return b1;
}

int main () {
	scanf("%d", &n);
	for (int i=1; i<n; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		adj[a].push_back(make_pair(b, c));
	}

	solve(1);
	printf("%d\n", ans);
	return 0;
}



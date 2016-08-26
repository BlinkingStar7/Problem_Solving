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

int n, m, ff, tt;
bool v[10001];
vpii adj[10001];

int main () {
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back(make_pair(c, b));
		adj[b].push_back(make_pair(c, a));
	}

	for (int i=1; i<=n; ++i)
		sort(adj[i].begin(), adj[i].end(), greater<pair<int, int> >());

	scanf("%d%d", &ff, &tt);

	int lo = 0, hi = 1e9;
	while (lo < hi) {
		int mid = (lo + hi)/2;
		memset(v, 0, sizeof(v));
		queue<int> q; q.push(ff);
		v[ff] = true;

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			if (cur == tt) break;
			for (int i=0; i<adj[cur].size(); ++i) {
				int next = adj[cur][i].second, vv = adj[cur][i].first;
				if (mid <= vv && !v[next]) {
					v[next] = true;
					q.push(next);
				}
			}
		}
		if (v[tt]) lo = mid+1;
		else hi = mid;
	}

	printf("%d\n", hi-1);

	return 0;
}



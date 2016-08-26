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
vpii adj[10001];
bool v[10001];

priority_queue<pii> pq;

void process(int c) {
	for (int i=0; i<adj[c].size(); ++i) {
		pii next = adj[c][i];
		if (!v[next.second]) pq.push(next);
	}
}

int main () {
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		adj[a].push_back(make_pair(c, b));
		adj[b].push_back(make_pair(c, a));
	}

	int ans = INF;
	scanf("%d%d", &ff, &tt);

	process(ff);
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();
		int w = cur.first, next = cur.second;
		if (!v[next]) {
			ans = min(ans, w);
			v[next] = true;
			if (next == tt) break;

			process(next);
		}
	}

	printf("%d\n", ans);

	return 0;
}



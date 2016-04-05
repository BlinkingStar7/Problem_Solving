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

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		int v, e;
		vi adj[20001];

		scanf("%d%d", &v, &e);

		for (int i=0; i<e; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			--a, --b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int c[20001]; bool ans = true;
		memset(c, -1, sizeof(c));

		for (int i=0; i<v; ++i) {
			queue<int> q;
			if (c[i] == -1) {
				c[i] = 0;
				q.push(i);
			}

			while(!q.empty() && ans) {
				int cur = q.front(); q.pop();
				for (int ii=0; ii<adj[cur].size(); ++ii) {
					int next = adj[cur][ii];
					if (c[next] == -1) {
						c[next] = 1- c[cur];
						q.push(next);
					}
					else if (c[next] == c[cur]) ans = false;
				}
			}
			if (!ans) break;
		}

		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}



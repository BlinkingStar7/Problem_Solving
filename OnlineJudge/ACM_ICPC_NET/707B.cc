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
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 100005;
int N, M, K, V[MAX];
vpii adj[MAX];
int main () {
	scanf("%d%d%d", &N, &M, &K);
	for (int i=0; i<M; ++i) {
		int a, b, w; 
		scanf("%d%d%d", &a, &b, &w);
		adj[a].push_back(make_pair(b, w));
		adj[b].push_back(make_pair(a, w));
	}

	for (int i=0; i<K; ++i) {
		int t;
		scanf("%d", &t);
		V[t] = true;
	}

	int ans = 1000000001;
	for (int i=1; i<=N; ++i) {
		if (!V[i]) {
			for (int j=0; j<adj[i].size(); ++j) if (V[adj[i][j].first])	
				ans = min (ans, adj[i][j].second);
		}
	}

	if (K == 0 || ans == 1000000001) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}



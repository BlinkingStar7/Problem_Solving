#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e9
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

int n, m, p, store[15];
double dist[51][51], profit[13], memo[13][1<<13];

double solve(int cur, int visited) {
	double &ret = memo[cur][visited];
	if (ret != INF) return ret;

	int curIndex = store[cur];
	ret = dist[curIndex][0];

	for (int next=1; next<=p; ++next) {
		int nextIndex = store[next];
		if (!(visited & (1<<next)))
			ret = min(ret, dist[curIndex][nextIndex] - profit[next] + solve(next, visited|(1<<next)));
	}

	return ret;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d%d", &n,&m);
		fill(&dist[0][0], &dist[0][0] + sizeof(dist)/sizeof(double), INF);
		for (int i=0; i<=n; ++i) dist[i][i] = 0;

		for (int i=0; i<m; ++i) {
			int u,v; double d;
			scanf("%d%d%lf", &u,&v,&d);
			dist[u][v] = dist[v][u] = min(d, dist[v][u]);
		}
		scanf("%d", &p);
		for (int i=1; i<=p; ++i) 
			scanf("%d%lf", &store[i], &profit[i]);

		for (int k=0; k<=n; ++k)
			for (int i=0; i<=n; ++i)
				for (int j=0; j<=n; ++j)
					dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);


		fill(&memo[0][0], &memo[0][0] + sizeof(memo)/sizeof(double), INF);

		double cand = solve(0, 1);
		if (cand < -EPSILON) printf("Daniel can save $%.2lf\n", -cand);
		else printf("Don't leave the house\n");
	}

	return 0;
}



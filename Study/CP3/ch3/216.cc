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

int n, x[10], y[10];
double memo[10][1<<10], dist[10][10];

double solve(int cur, int visited) {
	if (visited == (1<<n) -1) return 0;

	double &ret = memo[cur][visited];
	if (ret >= 0) return ret;

	ret = INF;

	for (int next=0; next<n; ++next)
		if ((visited & (1<<next)) == 0)
			ret = min(ret, dist[cur][next] + solve(next, visited|(1<<next)));

	return ret;
}

void reconstruct(vi& ans, int cur, int visited) {
	ans.push_back(cur);
	for (int next=0; next<n; ++next)
		if ((visited & (1<<next)) == 0)
			if (dist[cur][next] + solve(next, visited|(1<<next)) == solve(cur, visited))
				return reconstruct(ans, next, visited|(1<<next));
}
				
int main () {
	int cnt = 1;
	while (scanf("%d", &n) && n) {
		for (int i=0; i<n; ++i)
			scanf("%d%d", x+i, y+i);
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				dist[i][j] = dist[j][i] = hypot(x[i]-x[j], y[i]-y[j]);

		fill(&memo[0][0], &memo[0][0] + sizeof(memo)/sizeof(double), -1);

		double minVal = INF; int minStart = -1;
		for (int i=0; i<n; ++i) {
			double cand = solve(i, 1<<i);
			DPRINTF(("start from %d = %.2lf\n", i, cand));
			if (cand < minVal) {
				minVal = cand;
				minStart = i;
			}
		}

		vi ans;
		reconstruct(ans, minStart, 1<<minStart);


		printf("**********************************************************\n");
		printf("Network #%d\n",cnt++);

		double sum = 0;
		for (int i=0; i<n-1; ++i) {
			int a = ans[i], b = ans[i+1];
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", x[a],y[a],x[b],y[b],dist[a][b]+16.0);
			sum += dist[a][b]+16.0;
		}
		printf("Number of feet of cable required is %.2lf.\n", sum);
	}

	return 0;
}



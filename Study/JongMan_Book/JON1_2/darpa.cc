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

int n, m;
double dist[201];

bool solve(double limit, int cur, int left) {
	if (left == 0) return true;
	
	for (int next = cur+1; next<m; ++next) {
		if (dist[next] - dist[cur] >= limit - EPSILON)
			return solve(limit, next, left-1);
	}
	return false;
}

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<m; ++i) scanf("%lf", dist+i);

		double lo = 0, hi = 240;
		for (int it=0; it<100; ++it) {
			double mid = lo + (hi-lo)/2;
			if (solve(mid, 0, n-1)) lo = mid;
			else hi = mid;
		}

		printf("%.2lf\n", hi);
	}
	return 0;
}



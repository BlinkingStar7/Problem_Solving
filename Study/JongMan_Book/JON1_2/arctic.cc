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

pair<double, double> pos[101];
double dist[101][101];
int n;

bool solve(double d) {
	vb visited(n, false); int num = 0;
	queue<int> q;
	q.push(0); visited[0] = true; num++;

	while (!q.empty()) {
		int here = q.front(); q.pop();
		for (int there=0; there<n; ++there) {
			if (!visited[there] && dist[here][there] <= d) {
				visited[there] = true;
				++num;
				q.push(there);
			}
		}
	}
	return num == n;
}

int main () {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%lf%lf", &pos[i].first, &pos[i].second);

		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				dist[i][j] = hypot(pos[i].first - pos[j].first, pos[i].second - pos[j].second);
		double lo = 0, hi = 2000;
		for (int i=0; i<100; ++i) {
			double mid = lo +(hi-lo)/2;
			if (solve(mid)) hi = mid;
			else lo = mid;
		}

		printf("%.2lf\n", hi);
	}


	return 0;
}



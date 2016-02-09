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

int c,r,x[11],y[11],memo[11][1<<11],n;
inline int dist(int a, int b) {
	return abs(x[a]-x[b]) + abs(y[a]-y[b]);
}

int solve(int cur, int visited) {
	if (visited == (1<<(n+1))-1) return dist(cur, 0);

	int &ret = memo[cur][visited];
	if (ret != -1) return ret;

	ret = INF;

	for (int next=1; next<=n; ++next)
		if (!(visited & (1<<next)))
			ret = min(ret, dist(cur, next) + solve(next, visited|(1<<next)));
	return ret;
}

int main () {
	int t;
	cin >> t;
	while(t--) {
		scanf("%d%d",&c,&r);
		scanf("%d%d",x+0, y+0);
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%d%d",x+i+1, y+i+1);

		memset(memo, -1, sizeof(memo));
		printf("The shortest path has length %d\n", solve(0, 1));
	}
	return 0;
}



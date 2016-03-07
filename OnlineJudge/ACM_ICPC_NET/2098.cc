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

int n, memo[17][1<<16], W[17][17];
int solve(int cur, int visited) {
	if (visited == (1<<n) - 1) return W[cur][0];

	int &ret = memo[cur][visited];
	if (ret != -1) return ret;

	ret = INF;
	for (int next=0; next<n; ++next) {
		if (!(visited & (1<<next)) && W[cur][next])
			ret = min (ret, W[cur][next] + solve(next, visited | (1<<next)));
	}
	return ret;
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) scanf("%d", &W[i][j]);
	memset(memo, -1, sizeof(memo));
	printf("%d\n", solve(0, 1));
	return 0;
}



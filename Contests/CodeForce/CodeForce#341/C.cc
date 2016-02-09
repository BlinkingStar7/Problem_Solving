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

long long n, p;
double P[100001], memo[100001][2][2];
double solve(int cur, int prev, int start) {
	if (cur == n-1) {
		if (start && !prev) return P[cur]*4000 + (1-P[cur])*2000;
		if (start && prev) return 2000;
		if (!start&& !prev) return P[cur]*4000;
		if (!start&& prev) return P[cur]*2000;
	}

	double &ret = memo[cur][prev][start];
	if (ret >= -EPSILON) return ret;

	ret = 0;
	if (prev) return ret = P[cur]*(2000+solve(cur+1, 1, start)) + (1-P[cur])*solve(cur+1, 0, start);
	else return ret = P[cur]*(4000+solve(cur+1, 1, start)) + (1-P[cur])*solve(cur+1, 0, start);
}

int main () {
	cin >> n >> p;
	for (int i=0; i<n; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		P[i] = (double)(r/p - (l+p-1)/p + 1) / (r-l+1);
	}

	double ans = 0;
	for (int i=0; i<n; ++i)
		memo[i][0][0] = memo[i][0][1] = memo[i][1][1] = memo[i][1][0] = -1.0;

	printf("%lf\n", P[0]*(2000+solve(1,1,1)) + (1-P[0])*solve(1,0,0));
	return 0;
}



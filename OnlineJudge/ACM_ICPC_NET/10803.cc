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

int memo[101][10001];
int solve(int a, int b) {
	if (a > b) swap(a, b);
	if (a == 0) return 0;

	int &ret = memo[a][b];
	if (ret != -1) return ret;

	ret = INF;

	for (int i=1; i<=a; ++i)
		ret = min(ret, 1+min(solve(a-i,b) + solve(i, b-i), solve(a-i, i) + solve(a, b-i)));

	return ret;
}

int main () {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(memo, -1, sizeof(memo));
	printf("%d\n", solve(n, m));
	return 0;
}



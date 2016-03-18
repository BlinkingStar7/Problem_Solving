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

int n, a[2001], b[2001], memo[2001][2001];
int solve (int aa, int bb) {
	if (aa == n || bb == n) return 0;

	int &ret = memo[aa][bb];
	if (ret != -1) return ret;

	ret = max(solve(aa+1, bb+1), solve(aa+1, bb));
	if (a[aa] > b[bb]) ret = max(ret, b[bb] + solve(aa, bb+1));

	return ret;
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", a+i);
	for (int i=0; i<n; ++i) scanf("%d", b+i);
	
	memset(memo, -1, sizeof(memo));
	printf("%d\n", solve(0, 0));
	
	return 0;
}



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

int n, memo[10001][3], wine[10001];
int solve(int cur, int cons) {
	if (cur == n) return 0;
	
	int &ret = memo[cur][cons];
	if (ret != -1) return ret;

	if (cons == 2) ret = solve(cur+1, 0);
	else ret = max(solve(cur+1,cons+1) + wine[cur], solve(cur+1, 0));

	return ret;
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", wine+i);

	memset(memo, -1, sizeof(memo));
	printf("%d\n", solve(0, 0));
	return 0;
}



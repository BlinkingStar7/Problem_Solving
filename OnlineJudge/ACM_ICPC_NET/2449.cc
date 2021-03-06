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

int n, k, cnt, arr[201], memo[201][201][21];

int solve(int a, int b, int to) {
	if (a == b)	return arr[a] == to ? 0 : 1;

	int &ret = memo[a][b][to];
	if (ret != -1) return ret;

	ret = INF;

	for (int x=a; x<b; ++x)
		ret = min(ret, solve(a, x, to) + solve(x+1, b, to));

	for (int kk=1; kk<=k; ++kk) 
		if (kk == to) continue;
		else ret = min(ret, 1+solve(a, b, kk));


	return ret;
}


int main () {
	scanf("%d%d",&n,&k);
	int bef = -1;
	for (int i=0; i<n; ++i) {
		int cur; scanf("%d", &cur);
		if (cur != bef) arr[cnt++] = cur;
		bef = cur;
	}
	memset(memo, -1, sizeof(memo));
	int ans = INF;
	for (int i=1; i<=k; ++i)
		ans = min (ans, solve(0, cnt-1, i));
	printf("%d\n", ans);
	return 0;
}



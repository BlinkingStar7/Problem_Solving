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

int n, children[201], memo[201];

int solve(int cur) {
	int &ret = memo[cur+1];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = cur+1; next<n; ++next)
		if (cur == -1 || children[next] > children[cur])
			ret = max (ret, 1+solve(next));
	return ret;
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", children+i);

	memset (memo, -1, sizeof(memo));
	printf("%d\n", n-(solve(-1)-1));

	return 0;
}



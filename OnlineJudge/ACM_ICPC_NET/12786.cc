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

int N, T, memo[101][21];
bool H[101][21];

int Solve (int cur, int h) {
	if (cur == N) return 0;

	int &ret = memo[cur][h];
	if (ret != -1) return ret;

	ret = INF;
	if (H[cur+1][h]) ret = min(ret, Solve(cur+1, h));
	if (h+1<=20 && H[cur+1][h+1]) ret = min(ret, Solve(cur+1, h+1));
	if (h-1>=1 && H[cur+1][h-1]) ret = min(ret, Solve(cur+1, h-1));
	if (H[cur+1][min(20, h*2)]) ret = min(ret, Solve(cur+1, min(20, h*2)));

	for (int i=1; i<=20; ++i) if (H[cur+1][i])
		ret = min(ret, 1+Solve(cur+1, i));

	return ret;
}

int main () {
	scanf("%d%d", &N, &T);
	for (int i=1; i<=N; ++i) {
		int n;
		scanf("%d", &n);
		for (int j=0; j<n; ++j) {
			int t;
			scanf("%d", &t);
			H[i][t] = true;
		}
	}

	memset(memo, -1, sizeof(memo));
	int ret = Solve(0, 1);
	printf("%d\n", ret > T ? -1 : ret);

	return 0;
}



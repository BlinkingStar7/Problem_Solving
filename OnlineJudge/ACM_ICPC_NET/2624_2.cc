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

int T, K, P[101], N[101], memo[101][10001];

int Solve(int cur, int left) {
	if (left == 0) return 1;
	if (cur == K) return left ? 0 : 1;

	int &ret = memo[cur][left];
	if (ret != -1) return ret;

	ret = 0;
	for (int i=0; i<=N[cur] && i*P[cur] <= left; ++i)
		ret += Solve(cur+1, left - i*P[cur]);
	return ret;
}

int main () {
	scanf("%d%d", &T,&K);
	for (int i=0; i<K; ++i)
		scanf("%d%d", P+i, N+i);

	memset(memo, -1, sizeof(memo));
	printf("%d\n", Solve(0, T));
	return 0;
}



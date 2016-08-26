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
typedef long long ll;
typedef unsigned long long ull;

int N, A[105], memo[105][5];
int Solve (int cur, int bef) {
	if (cur == N) return 0;

	int &ret = memo[cur][bef];
	if (ret != -1) return ret;

	ret = INF;
	if (A[cur]/2 && bef != 1) ret = min(ret, Solve(cur+1, 1));
	if (A[cur]%2 && bef != 2) ret = min(ret, Solve(cur+1, 2));
	
	return ret = min(ret, 1+Solve(cur+1, 0));
}

int main () {
	scanf("%d", &N);
	for (int i=0; i<N; ++i)
		scanf("%d", A+i);

	memset(memo, -1, sizeof(memo));
	printf("%d\n", Solve(0, 0));
	return 0;
}



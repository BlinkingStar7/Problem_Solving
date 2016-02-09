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

int N, cost[101];
int M, mem[101], memo[2][10001];

int main () {
	scanf("%d%d", &N,&M);
	int csum = 0;
	for (int i=0; i<N; ++i) scanf("%d", mem+i);
	for (int i=0; i<N; ++i) {
		scanf("%d", cost+i);
		csum +=cost[i];
	}


	for (int cur=0; cur<N; ++cur)
		for(int c=0; c<=csum; ++c) {
			memo[cur%2][c] = max(memo[(cur+1)%2][c], (c>=cost[cur] ? memo[(cur+1)%2][c-cost[cur]] + mem[cur] : 0));
		}

	printf("%d\n", lower_bound(&memo[(N-1)%2][0], &memo[(N-1)%2][csum+1], M) - &memo[(N-1)%2][0]);
	return 0;
}



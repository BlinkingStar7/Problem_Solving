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

int N, M, A[1025][1025];
int main () {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
		scanf("%d", &A[i+1][j+1]);
		A[i+1][j+1] += A[i][j+1] + A[i+1][j] - A[i][j];
	}

	for (int i=0; i<M; ++i) {
		int x, y, xx, yy;
		scanf("%d%d%d%d", &x, &y, &xx, &yy);
		printf("%d\n", A[xx][yy] - A[x-1][yy] - A[xx][y-1] + A[x-1][y-1]);
	}

	return 0;
}



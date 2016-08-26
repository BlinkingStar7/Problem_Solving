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

int N, A, B[100005], ans;
int main () {
	scanf("%d%d", &N, &A);
	if (N == 1) { return 0*printf("0\n"); }
	for (int i=0; i<N; ++i) scanf("%d", B+i);
	sort(B, B+N);

	int ans = INF;
	if (B[N-2] < A) ans = min(ans, A-B[0]);
	else if (B[0] > A) ans = min(ans, B[N-2]-A);
	else ans = min(ans, B[N-2]-B[0]+min(A-B[0], B[N-2]-A));

	if (B[N-1] < A) ans = min(ans, A-B[1]);
	else if (B[1] > A) ans = min(ans, B[N-1]-A);
	else ans = min(ans, B[N-1]-B[1]+min(A-B[1], B[N-1]-A));

	printf("%d\n", ans);
	return 0;
}



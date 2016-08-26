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

const int MAX = 200005;
int N, W, F[MAX] ,A[MAX], B[MAX], diff_A[MAX], diff_B[MAX], ans;

int main () {
	scanf("%d%d", &N, &W);
	// if (W == 1) return 0*printf("%d\n", N);

	for (int i=0; i<N; ++i) scanf("%d", A+i);
	for (int i=0; i<W; ++i) scanf("%d", B+i);

	for (int i=0; i<N-1; ++i) diff_A[i] = A[i+1]-A[i];
	for (int i=0; i<W-1; ++i) diff_B[i] = B[i+1]-B[i];

	for (int i=1, m=0; i<W-1; ++i) {
		while (m && diff_B[m] != diff_B[i]) m = F[m-1];
		if (diff_B[m] == diff_B[i]) F[i] = ++m;
	}

	for (int i=0, m=0; i<N-1; ++i) {
		while (m && diff_B[m] != diff_A[i]) m = F[m-1];
		if (diff_B[m] == diff_A[i]) {
			if (++m == W-1) {
				++ans;
				m = F[m-1];
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}



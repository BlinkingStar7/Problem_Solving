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

int N, B[200005], ans = 1000000005;
char A[200005];

int main () {
	scanf("%d", &N);
	scanf("%s", A);
	for (int i=0; i<N; ++i)
		scanf("%d", B+i);

	for (int i=0; i<N-1; ++i) {
		if (A[i] == 'R' && A[i+1] == 'L')
			ans = min (ans, (B[i+1]-B[i])/2);
	}

	printf("%d\n", ans == 1000000005 ? -1 : ans);
	return 0;
}



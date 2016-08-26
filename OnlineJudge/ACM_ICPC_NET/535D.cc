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

const int MAX = 1000005, MOD = 1000000007;
int N, M, len, Z[MAX];
char A[MAX];
bool can[MAX];


int main () {
	scanf("%d%d ", &N, &M);
	gets(A);
	len = strlen(A);

	for (int i=1, m=0; i<len; ++i) {
		while (m && A[m] != A[i]) m = Z[m-1];
		if (A[m] == A[i]) Z[i] = ++m;
	}
	
	while (Z[len-1]) {
		can[Z[len-1]] = true;
		Z[len-1] = Z[Z[len-1]-1];
	}

	int num = 0, last = 0;

	for (int i=0; i<M; ++i) {
		int t;
		scanf("%d", &t);
		if (t > last) num += t - last - 1;
		else if (!can[last - t + 1]) return 0*printf("0\n");
		
		last = t + len - 1;
	}

	if (N > last) num += N - last;

	long long ans = 1;
	while (num--)
		ans = (ans*26)%MOD;

	printf("%lld\n", ans);
	return 0;
}



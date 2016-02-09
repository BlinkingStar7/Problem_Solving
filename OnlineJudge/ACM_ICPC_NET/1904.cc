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

const int MOD = 15746;

int main () {
	int n, memo[1000001];
	cin >> n;

	memo[1] = 1, memo[2] = 2;
	for (int i=3; i<=n; ++i)
		memo[i] = (memo[i-1] + memo[i-2])%MOD;

	printf("%d\n", memo[n]);
	return 0;
}



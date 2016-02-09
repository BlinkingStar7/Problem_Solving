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

int main () {
	int n;
	scanf("%d", &n);
	n%=60;
	int memo[3];
	memo[0] = memo[1] = 1;
	for (int i=2; i<=n; ++i)
		memo[i%3] = (memo[(i-1)%3] + memo[(i-2)%3])%10;
	printf("%d\n", memo[n%3]);
	return 0;
}



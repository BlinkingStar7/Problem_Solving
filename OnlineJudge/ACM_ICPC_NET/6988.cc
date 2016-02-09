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

int dp[3001][3001], A[3001];
int main () {
	int n;
	cin >> n;
	for (int i=0; i<n; ++i) scanf("%d", A+i);

	long long ans = 0;

	for (int a=n-3; a>=0; --a)
		for (int b=n-2; b>a; --b) {
			int c = A[b] + (A[b] - A[a]);
			auto it = lower_bound(A, A+n, c);
			if (it != A+n && *it == c)
				dp[a][b] = dp[b][it-A]+1;

			int num = dp[a][b] + 2;
			if (num >= 3) {
				long long cand =(long long)(A[a] + (num-1)*(A[b]-A[a]) + A[a])*num/2;
				ans = max(ans, cand);
			}
		}

	printf("%lld\n", ans);
							
	return 0;
}



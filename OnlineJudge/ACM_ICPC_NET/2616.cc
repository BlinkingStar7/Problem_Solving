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

int n, limit, num[50002], dp[3][50002];
int main () {
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d", num+i);
		num[i] += num[i-1];
	}
	scanf("%d", &limit);

	for (int i=2; i>=0; --i)
		for (int j=n; j>=1; --j) {
			int right = j+limit-1 > n ? n : j+limit-1;
			int sum = num[right] - num[j-1];
			if (i==2) dp[i][j] = max(sum, dp[i][j+1]);
			else dp[i][j] = max(dp[i][j+1], sum + dp[i+1][right+1]);
		}

	printf("%d\n", dp[0][1]);
	return 0;
}



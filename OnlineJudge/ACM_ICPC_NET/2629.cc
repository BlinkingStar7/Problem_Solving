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

int n, coin[31], m;
bool dp[31][15001];

int main () {
	cin >> n;
	int sum = 0;
	for (int i=0; i<n; ++i) {
		scanf("%d", coin+i);
		sum += coin[i];
	}

	dp[n-1][0] = dp[n-1][coin[n-1]] = true;
	for (int c=n-2; c>=0; --c) {
		for (int m=sum; m>=0; --m)
			dp[c][m] = dp[c+1][m-coin[c]] || dp[c+1][m];
	}
	cin >> m;
	for (int i=0; i<m; ++i) {
		int t;
		scanf("%d", &t);
		bool ans = false;
		for (int right = t; right <= sum; ++right)
			if (dp[0][right] && dp[0][right-t]) {
				ans = true;
				break;
			}
		printf("%c%c",ans ? 'Y' : 'N', i==m-1 ? '\n' : ' ');
	}
	return 0;
}



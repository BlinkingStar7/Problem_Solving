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

int board[100001][3], dp[2][2][3];
int main () {
	int n;
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<3; ++j)
			scanf("%d", &board[i][j]);

	for (int x=0; x<2; ++x)
	for (int i=n-1; i>=0; --i)
		for (int j=0; j<3; ++j) {
			int num = board[i][j]*(x? 1 : -1);
			int &cur = dp[x][i%2][j];
			if (i == n-1) cur = num;
			else {
				int left = max(dp[x][(i+1)%2][0], dp[x][(i+1)%2][1]);
				int right= max(dp[x][(i+1)%2][1], dp[x][(i+1)%2][2]);
				if (j==0) cur = num + left;
				if (j==1) cur = num + max(left, right);
				if (j==2) cur = num + right;
			}
		}

	printf("%d %d\n", *max_element(&dp[1][0][0], &dp[1][0][3]), -*max_element(&dp[0][0][0], &dp[0][0][3]));


	return 0;
}



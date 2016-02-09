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

int board[501][501], memo[505][505];
int main () {
	int n;
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<=i; ++j)
			scanf("%d", &board[i][j]);

	for (int i=n-1; i>=0; --i)
		for (int j=i; j>=0; --j) {
			memo[i][j] = board[i][j] + max(memo[i+1][j], memo[i+1][j+1]);
		}

	printf("%d\n", memo[0][0]);
	return 0;
}



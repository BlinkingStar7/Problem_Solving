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

int board[501][501];
int main () {
	int n, k;
	cin >> n >> k;
	int num = n*n, sum = 0;
	for (int i=n; i>=1; --i)
		for (int j=n; j>=k; --j) {
			board[i][j] = num--;
			if (j == k) sum += board[i][j];
		}
	for (int i=n; i>=1; --i)
		for (int j=k-1; j>=1; --j)
			board[i][j] = num--;

	cout << sum << endl;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j)
			printf("%d ", board[i][j]);
		puts("");
	}


	return 0;
}



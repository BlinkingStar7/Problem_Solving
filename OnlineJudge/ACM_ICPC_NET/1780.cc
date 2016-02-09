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

int size, board[81*27][81*27], ans[3];

void solve(int n, int y, int x) {
	bool flag = true;
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j)
		if (board[y][x] != board[y+i][x+j]) {
			flag = false; break;
		}

	if (flag) {
		++ans[board[y][x]+1];
		return;
	}

	for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) {
		int nn = n/3, yy = y+nn*i, xx = x+nn*j;
		solve(nn, yy, xx);
	}
}

int main () {
	scanf("%d", &size);
	for (int i=0; i<size; ++i) for (int j=0; j<size; ++j) scanf("%d",&board[i][j]);
	solve(size, 0, 0);
	for (int i=0; i<3; ++i) printf("%d\n", ans[i]);
	return 0;
}



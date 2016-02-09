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

char board[101][101];
int N;
const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool dfs (int y, int x) {
	if (y<0 || x<0 || y>=N || x>=N) return false;
	if (board[y][x] == '.') return false;

	bool ret = board[y][x] == 'x';
	board[y][x] = '.';
	for (int dir=0; dir<4; ++dir) {
		int ny = y+d[dir][0], nx = x+d[dir][1];
		ret = dfs (ny, nx) || ret;
	}
	return ret;
}

int main () {
	int t;
	scanf("%d", &t);
	for (int tt=1; tt<=t; ++tt) {
		scanf("%d ", &N);
		for (int i=0; i<N; ++i) gets(board[i]);
		int ans = 0;
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				if (board[i][j] != '.') {
					if (dfs(i, j))
						++ans;
				}
		printf("Case %d: %d\n", tt, ans);
	}

	return 0;
}



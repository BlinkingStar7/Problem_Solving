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

const int dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};
char board[21][21];
int R, C;

inline bool isSafe(int y, int x) { return y>=0 && x>=0 && y<R && x<C; }
int dfs(int y, int x, char from) {
	board[y][x] = 0;
	int ret = 1;
	for (int d=0; d<4; ++d) {
		int ny = y+dy[d], nx = x+dx[d];
		if (nx == C) nx = 0;
		if (nx == -1) nx = C-1;
		if (isSafe(ny, nx) && board[ny][nx] == from)
			ret += dfs (ny, nx, from);
	}
	return ret;
}

int main () {
	while(scanf("%d%d ", &R, &C) != EOF) {
		for (int i=0; i<R; ++i) gets(board[i]);
		int y, x;
		scanf("%d%d",&y,&x);
		char from = board[y][x];
		dfs(y, x, from);

		int ans = 0;
		for (int i=0; i<R; ++i) for (int j=0; j<C; ++j) 
			if (board[i][j] == from) { 
				int cand = dfs(i, j, from);
				ans = max(ans, cand);
			}
		printf("%d\n", ans);
	}
		return 0;
}



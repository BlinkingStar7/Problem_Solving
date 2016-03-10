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

const int dy[4]={0,-1,0,1}, dx[4]={1,0,-1,0};
int m, n, board[111][111];

inline bool isSafe(int y, int x) {
	return y>=0 && x>=0 && y<m && x<n;
}

void dfs (int y, int x, int from, int to) {
	board[y][x] = to;
	for (int d=0; d<4; ++d) {
		int ny=y+dy[d], nx=x+dx[d];
		if (isSafe(ny, nx) && board[ny][nx] == from)
			dfs(ny, nx, from, to);
	}
}

int main () {
	scanf("%d%d", &m, &n);
	for (int i=0; i<m; ++i) for (int j=0; j<n; ++j)
		scanf("%d", &board[i][j]);

	int time = 0, bef = 0, cur = 0;
	while(1) {
		dfs(0, 0, 0, -1);

		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				if (board[i][j] != 1) continue;
				bool melt = false; 
				for (int d=0; d<4; ++d) {
					int ny = i+dy[d], nx = j+dx[d];
					if (isSafe(ny, nx) && board[ny][nx] == -1) {
						melt = true;
						break;
					}
				}
				if (melt) board[i][j] = 2;
			}
		}

		bef = cur;
		cur = 0;
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j)
			if (board[i][j] == -1) board[i][j] = 0;
			else if (board[i][j] == 2) {board[i][j] = 0; ++cur;}

		if (cur == 0) break;
		++time;
	}

	printf("%d\n%d\n", time, bef);			

	return 0;
}



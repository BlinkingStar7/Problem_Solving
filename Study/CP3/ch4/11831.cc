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

int r, c, s;
char board[101][101];
char move[50001];
const char* dir = "LNOS";
int Map[300];
const int dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};

void init() {
	for (int d=0; d<4; ++d)
		Map[dir[d]] = d;
}

inline bool isSafe (int y, int x) { return y>=0&&x>=0&&y<r&&x<c; }

int go (int y, int x, int dir, int pos) {
	int ret = 0;
	if (board[y][x] == '*') {
		++ret;
		board[y][x] = '.';
	}

	if (pos == s) return ret;

	if (move[pos] == 'D')
		dir = (dir+3)%4;
	else if (move[pos] == 'E')
		dir = (dir+1)%4;
	else {
		int ny = y+dy[dir], nx=x+dx[dir];
		if (isSafe(ny, nx) && board[ny][nx] != '#') {
			y = ny, x = nx;
		}
	}
	return ret + go (y, x, dir, pos+1);
}




int main () {
	init();

	while (scanf("%d%d%d",&r,&c,&s)) {
		if (r == 0 && c == 0 && s == 0) break;

		getchar();
		for (int i=0; i<r; ++i)
			gets(board[i]);
		gets(move);

		int starty,startx;
		for (int i=0; i<r; ++i)
			for (int j=0; j<c; ++j)
				if (isalpha(board[i][j])) {
					starty = i, startx = j;
					break;
				}

		printf("%d\n", go(starty, startx, Map[board[starty][startx]], 0));
	}
		
	return 0;
}



#include <bits/stdc++.h>
#ifdef DEBUG
#define DPRINTF(x) printf x
#else 
#define DPRINTF(x) ;
#endif
using namespace std;

int total, n, m, board[301][301], newBoard[301][301];
bool visited[301][301];
const int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

inline bool isSafe(int y, int x) {
	return y>=0 && x>=0 && y<n && x<m;
}

void melt(int y, int x) {
	visited[y][x] = true;
	newBoard[y][x] = board[y][x];

	for (int d=0; d<4; ++d) {
		int ny=y+dy[d], nx=x+dx[d];
		if (isSafe(ny, nx)) {
			if (board[ny][nx] == 0)
				--newBoard[y][x];
			else if (!visited[ny][nx])
				melt(ny, nx);
		}
	}
	newBoard[y][x] = newBoard[y][x] > 0 ? newBoard[y][x] : 0;
}

int main () {
	cin >> n >> m;
	
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j) {
			scanf("%d", &board[i][j]);
		}

	int time=0;
	while(1) {
		memset(newBoard, 0, sizeof(newBoard));
		memset(visited, false, sizeof(visited));
		int cnt=0;

		for (int i=0; i<n; ++i){
			for (int j=0; j<m; ++j) {
				DPRINTF(("%d ", board[i][j]));
				if (board[i][j] && !visited[i][j]) {
					++cnt;
					melt(i, j);
				}
			}
			DPRINTF(("\n"));
		}
		DPRINTF(("cnt : %d \n", cnt));
		if (cnt == 0) {
			time = 0;
			break;
		}
		else if (cnt >= 2) break;

		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				board[i][j] = newBoard[i][j];
		++time;
	}

	printf("%d\n", time);
	return 0;
}


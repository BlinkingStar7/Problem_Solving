#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};
int board[30][30], size;

inline bool isSafe (int y, int x) { return y>=0&&x>=0&&y<size&&x<size; }

int dfs(int y, int x) {
	board[y][x] = 0;
	int ret = 1;

	for (int dir=0; dir<4; ++dir) {
		int ny = y+dy[dir], nx = x+dx[dir];
		if (isSafe(ny, nx) && board[ny][nx] == 1)
			ret += dfs(ny, nx);
	}
	
	return ret;
}

int main() {
	scanf("%d", &size);

	for (int i=0; i<size; ++i)
		for (int j=0; j<size; ++j)
			scanf("%1d", &board[i][j]);

	vector<int> list;

	for (int i=0; i<size; ++i)
		for (int j=0; j<size; ++j)
			if (board[i][j] == 1)
				list.push_back(dfs(i, j));
	
	sort(list.begin(), list.end());

	printf("%d\n", (int)list.size());
	for (int i=0; i<list.size(); ++i)
		printf("%d\n", list[i]);

	return 0;
}

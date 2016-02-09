#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
using namespace std;

const int dy[4] = {0, 1, 1, 1}, dx[4] = {1, 1, 0, -1};
int C, Memo[20000];
char Board[4][4];

int State (char (&board)[4][4]) {
	int ret = 0;
	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j) {
			ret *= 3;
			if (board[i][j] == 'x') ret += 1;
			else if (board[i][j] == 'o') ret += 2;
		}
	return ret;
}

int Traverse (char (&board)[4][4], char start, int y, int x, int d, int num) {
	if (y>=3 || x>=3 || y<0 || x<0) return 0;
	if (board[y][x] != start) return 0;
	if (num == 1) return 1;

	int ny = y + dy[d], nx = x + dx[d];
	return Traverse (board, start, ny, nx, d, num-1);
}


int isover(char (&board)[4][4]) {
	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j) {
			for (int d=0; d<4; ++d) {
				if (board[i][j] != '.' && Traverse(board, board[i][j], i, j, d, 3))
					return board[i][j];
			}
		}
	return 0;
}


int Solve (char (&board)[4][4], char turn) {
	int &ret = Memo[State(board)];
	if (ret != 2) return ret;

	if (isover(board)) return ret = -1;

	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j) {
			if (board[i][j] == '.') {
				board[i][j] = turn;
				ret = min (ret, Solve(board, 'x'+'o'-turn));
				board[i][j] = '.';
			}
		}

	if (ret == 2) return ret = 0;
	return ret = - ret;
}

int main () {
	cin >> C;

	while (C--) {
		for (int i=0; i<20000; ++i)
			Memo[i] = 2;

		int oNum=0, xNum = 0;
		for (int i=0; i<3; ++i) {
			cin.get();
			for (int j=0; j<3; ++j) {
				cin >> Board[i][j];
				if (Board[i][j] == 'x') ++xNum;
				else if (Board[i][j] == 'o') ++oNum;
			}
		}

		char turn = xNum == oNum ? 'x' : 'o';
		int ret = Solve (Board, turn);
		if (ret == -1) cout << (char)('x' + 'o' - turn) << endl;
		else if (ret == 0) cout << "TIE" << endl;
		else cout << turn << endl;
	}

	return 0;
}


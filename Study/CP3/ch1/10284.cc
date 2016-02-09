#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
using namespace std;
#define IFN 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif


const int dx[20] = {0,1,1,1,0,-1,-1,-1,1,2,2,1,-1,-2,-2,-1},
	  	  dy[20] = {-1,-1,0,1,1,1,0,-1,-2,-1,1,2,2,1,-1,-2};
inline bool isSafe(int i, int j) {
	return i>=0&&j>=0&&i<8&&j<8;
}
bool attack[10][10];
char board[10][10];
void go (int y, int x, int dy, int dx) {
	if (!isSafe(y, x) || board[y][x] != '.') return;
	attack[y][x] = true;
	go (y+dy, x+dx, dy, dx);
}

int main () {
	char input[1000];
	while(gets(input)) {
		memset(board, '.', sizeof(board));
		memset(attack, false, sizeof(attack));
		int r=0, c=0;
		for (int i=0; i<strlen(input); ++i) {
			if (isdigit(input[i])) c+=input[i]-'0';
			else if (input[i] == '/') {
				++r; c=0;
			}
			else board[r][c++] = input[i];
		}

		for (int i=0; i<8; ++i)
			for (int j=0; j<8; ++j) {
				if (tolower(board[i][j]) == 'q') {
					attack[i][j] = true;
					for (int d=0; d<8; ++d)
						go(i+dy[d], j+dx[d], dy[d], dx[d]);
				}
				else if (tolower(board[i][j]) == 'b') {
					attack[i][j] = true;
					for (int d=0; d<8; ++d) {
						if (d%2==0) continue;
						go(i+dy[d], j+dx[d], dy[d], dx[d]);
					}
				}
				else if (tolower(board[i][j]) == 'r') {
					attack[i][j] = true;
					for (int d=0; d<8; ++d) {
						if (d%2==1) continue;
						go(i+dy[d], j+dx[d], dy[d], dx[d]);
					}
				}
				else if (tolower(board[i][j]) == 'n') {
					attack[i][j] = true;
					for (int d=0; d<8; ++d) {
						int ny=i+dy[8+d], nx=j+dx[8+d];
						if (isSafe(ny, nx)) attack[ny][nx] = true;
					}
				}
				else if (tolower(board[i][j]) == 'k') {
					attack[i][j] = true;
					for (int d=0; d<8; ++d) {
						int ny=i+dy[d], nx=j+dx[d];
						if (isSafe(ny, nx)) attack[ny][nx] = true;
					}
				}
				else if (board[i][j] == 'p') {
					attack[i][j] = true;
					if (isSafe(i+1, j-1)) attack[i+1][j-1] = true;
					if (isSafe(i+1, j+1)) attack[i+1][j+1] = true;
				}
				else if (board[i][j] == 'P') {
					attack[i][j] = true;
					if (isSafe(i-1, j-1)) attack[i-1][j-1] = true;
					if (isSafe(i-1, j+1)) attack[i-1][j+1] = true;
				}
			}
		int ans = 0;
		for (int i=0; i<8; ++i) {
			for (int j=0; j<8; ++j) {
				if (attack[i][j]) ++ans;
				if (board[i][j] != '.') DPRINTF(("%c",board[i][j]));
				else if (attack[i][j]) DPRINTF(("x"));
				else DPRINTF(("."));
			}
			DPRINTF(("\n"));
		}

		cout << 64-ans << endl;
	}

			
	return 0;
}


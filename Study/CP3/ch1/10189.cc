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

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
	  	  dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}; 
int r,c;
char board[101][101];
inline bool isSafe(int y, int x) {
	return y>=0&&x>=0&&y<r&&x<c;
}


int main () {
	int cnt = 1;
	while(scanf("%d%d",&r,&c)) {
		if (r == 0 && c == 0) break;
		getchar();
		for (int i=0; i<r; ++i)
			gets(board[i]);
		for (int i=0; i<r; ++i)
			for (int j=0; j<c; ++j) {
				if (board[i][j] == '.') {
					int num = 0;
					for (int d=0; d<8; ++d) {
						int ny=i+dy[d], nx=j+dx[d];
						if (isSafe(ny, nx) && board[ny][nx] == '*')
							++num;
					}
					board[i][j] = num +'0';
				}
			}
		if (cnt > 1) puts("");
		printf("Field #%d:\n", cnt++);
		for (int i=0; i<r; ++i)
			printf("%s\n", board[i]);
	}
	return 0;
}


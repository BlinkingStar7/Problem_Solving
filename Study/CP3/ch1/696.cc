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

const int dy[10] = {0, 2, 1, -1, -2, -2, -1, 1, 2},
	      dx[10] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
int ans;
bool board[501][501];
int main () {
	int r,c;
	while(scanf("%d%d",&r,&c)) {
		if (r == 0 && c == 0) break;
		ans = 0;
		memset(board, false, sizeof(board));
		if (max(r, c) > 3) {
			if (min(r, c) == 1) ans = r*c;
			else if (min(r, c) == 2) ans = 4*(max(r,c)/4) + (max(r,c)%4 == 0 ? 0 : max(r,c)%4==1 ? 2 : 4);
			else ans = (r*c+1)/2;
		}
		else {
		for (int i=0; i<r; ++i)
			for (int j=0; j<c; ++j) {
				if((i+j)%2 == 0) {
					++ans;
					for (int d=0; d<9; ++d) {
						int ny=i+dy[d], nx=j+dx[d];
						if (ny>=0&&nx>=0&&ny<r&&nx<c)
							board[ny][nx] = true;
					}
				}
			}
		for (int i=0; i<r; ++i)
			for (int j=0; j<c; ++j) {
				if(!board[i][j]) {
					++ans;
					for (int d=0; d<9; ++d) {
						int ny=i+dy[d], nx=j+dx[d];
						if (ny>=0&&nx>=0&&ny<r&&nx<c)
							board[ny][nx] = true;
					}
				}
			}
		}
		printf("%d knights may be placed on a %d row %d column board.\n",ans, r, c);
	}
	return 0;
}


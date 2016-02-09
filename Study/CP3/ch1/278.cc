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

const int dy[11] = {0, 2, 1, -1, -2, -2, -1, 1, 2},
		  dx[11] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
char ch;
int r,c,ans,board[11][11];

int nQeen(int rr, vector<bool>& row, vector<bool>& col, vector<bool>&dig1, vector<bool>&dig2) {
	int ret = 0;
	if (rr == r) return 0;
	for (int i=rr; i==rr; ++i)
		for (int j=0; j<c; ++j) {
			if (!(row[i]||col[j]||dig1[(i-j)+c-1]||dig2[(i+j)])) {
				row[i] = col[j] = dig1[(i-j)+c-1] = dig2[(i+j)] = true;
				ret = max(ret, 1+nQeen(rr+1, row, col, dig1, dig2));
				row[i] = col[j] = dig1[(i-j)+c-1] = dig2[(i+j)] = false;
			}
		}
	return ret;
}

int main () {
	int t;
	scanf("%d", &t);
	while(t--) {
		getchar();
		scanf("%c%d%d",&ch,&r,&c);
		ans = 0;
		memset(board, 0, sizeof(board));

		if (ch == 'r') ans = min(r, c);
		if (ch == 'K') ans = ((r+1)/2)*((c+1)/2);
		if (ch == 'k') {
			for (int i=0; i<r; ++i)
				for (int j=0; j<c; ++j) {
					if ((i+j)%2 == 0) {
						++ans;
						for (int d=0; d<9; ++d) {
							int ny= i+dy[d], nx=j+dx[d];
							if (ny>=0&&nx>=0&&ny<r&&nx<c) {
								board[ny][nx] = 1;
							}
						}
					}
				}
			for (int i=0; i<r; ++i)
				for (int j=0; j<c; ++j)
					if (!board[i][j]) {
						++ans;
						for (int d=0; d<9; ++d) {
							int ny= i+dy[d], nx=j+dx[d];
							if (ny>=0&&nx>=0&&ny<r&&nx<c) {
								board[ny][nx] = 1;
							}
						}
					}
		}
		if (ch == 'Q') {
			vector<bool> row(r,false), col(c,false), dig1(r+c-1,false), dig2(r+c-1,false);
			ans = nQeen(0, row, col, dig1, dig2);
		}
		cout << ans << endl;
	}
			
	return 0;
}


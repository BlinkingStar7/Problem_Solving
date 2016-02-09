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
#define PI 2*acos(0.0)
#define IFN 1e8
#define EPSILON 1e-8
#define FOR(x,n) for (int x=0; x<n; ++x)
#define FORV(x,v) for (int x=0; x<(int)v.size(); ++v)
#define SCD(x) scanf("%d", &x)
#define SCDD(x, y) scanf("%d%d", &x, &y)
#define SCDDD(x, y, z) scanf("%d%d%d",&x, &y, &z)
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif

typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;

int r, c, n;
string s = "RSP";
bool win[300][300];
const int dy[4] = {-1, 0, 1, 0},
	      dx[4] = {0, 1, 0, -1};
char board[111][111];
inline bool isSafe(int y, int x) {
	return y>=0&&x>=0&&y<r&&x<c;
}

void init() {
	for (int i=0; i<3; ++i) {
		int j=(i+1)%3;
		win[s[i]][s[j]] = true;
	}
}

int main () {
	int t;
	SCD(t);
	init();
	FOR(cnt, t) {
		SCDDD(r, c, n);
		getchar();
		FOR(i, r)
			gets(board[i]);

		FOR(day, n) {
			char newBoard[111][111];
			FOR(i, r)
				FOR(j, c)
					newBoard[i][j] = board[i][j];

			FOR(i, r) {
				FOR(j, c) {
					FOR(d, 4) {
						int ny=i+dy[d], nx=j+dx[d];
						if (isSafe(ny, nx) && win[board[i][j]][board[ny][nx]]) {
							DPRINTF(("%d %d wins %d %d\n", i, j, ny,nx));
							newBoard[ny][nx] = board[i][j];
						}
					}
				}
			}

			FOR(i, r)
				FOR(j, c)
					board[i][j] = newBoard[i][j];
		}

		if (cnt > 0) puts("");
		FOR(i, r) {
			puts(board[i]);
		}
	}
		
	return 0;
}


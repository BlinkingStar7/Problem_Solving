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

int N, ans, board[10][10];
const int size[3] = {1, 2, 2},
		  dx[3][2] = {{0}, {0, 1}, {0, 0}},
		  dy[3][2] = {{0}, {0, 0}, {1, 0}};

inline bool isSafe(int y, int x) {	return y>=0 && x>= 0 && y<N && x<=y;}
bool cover (int y, int x, int shape, int alpha) {
	bool ret = true;
	for (int i=0; i<size[shape]; ++i) {
		int ny=y+dy[shape][i], nx=x+dx[shape][i];
		if (!isSafe(ny, nx) || board[ny][nx] == 1) {
			ret = false;
		}
		if (isSafe(ny, nx))
			board[ny][nx] += alpha;
		}
	return ret;
}

int solve(int y, int x) {
	if (x > y) return solve(y+1, 0);
	if (y == N) return 1;
	if (board[y][x] == 1) return solve(y, x+1);

	int ret = 0;
	
	for (int s=0; s<3; ++s) {
		if (cover(y, x, s, 1))
			ret += solve(y, x+1);
		cover(y, x, s, -1);
	}
	return ret;
}

int main () {
	scanf("%d", &N);
	printf("%d\n", solve(0, 0));
	return 0;
}



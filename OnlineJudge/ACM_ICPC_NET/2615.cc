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

const int dy[4] = {0, 1, 1, -1}, dx[4] = {1, 0, 1, 1};
int b[20][20];
inline bool isSafe (int y, int x) {
	return x>=0 && y>=0 && x<19 && y<19;
}

bool dfs(int y, int x, int n, int t, int d) {
	if (!isSafe(y, x) || b[y][x] != t) return false;
	if (n == 5 && isSafe(y-dy[d], x-dx[d]))
		if (b[y-dy[d]][x-dx[d]] == t) return false;

	int ny=y+dy[d], nx=x+dx[d];

	if (n == 1) return !isSafe(ny, nx) || b[ny][nx] != t;
	return dfs(ny, nx, n-1, t, d);
}

int main () {
	for (int i=0; i<19; ++i)
		for (int j=0; j<19; ++j) scanf("%d", &b[i][j]);

	for (int j=0; j<19; ++j) {
		for (int i=0; i<19; ++i) {
			if (b[i][j]) {
				bool ans = false;
				for (int d=0; d<4; ++d)
					ans = ans || dfs(i, j, 5, b[i][j], d);
				if (ans) {
					printf("%d\n%d %d\n", b[i][j], i+1, j+1);
					return 0;
				}
			}
		}
	}

	printf("0\n");
	return 0;
}



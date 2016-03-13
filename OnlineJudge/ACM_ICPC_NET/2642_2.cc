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

const int move[7][4][2] = {
	{},
	{{2, 0}, {5, 0}, {4, 0}, {6, 0}},
	{{3, 0}, {5, 1}, {1, 0}, {6, 3}},
	{{4, 0}, {5, 2}, {2, 0}, {6, 2}},
	{{1, 0}, {5, 3}, {3, 0}, {6, 1}},
	{{2, 3}, {3, 2}, {4, 1}, {1, 0}},
	{{2, 1}, {1, 0}, {4, 3}, {3, 2}}
},
	dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};

int b[7][7], ans[7];

inline bool isSafe(int y, int x) {
	return x>=0 && y>=0 && x<6 && y<6;
}

void dfs(int y, int x, int cur, int dir) {
	ans[cur] = b[y][x];
	for (int d=0; d<4; ++d) {
		int ny=y+dy[d], nx=x+dx[d];
		int next = move[cur][(d+dir+4)%4][0];
		if (isSafe(ny, nx) && b[ny][nx] && !ans[next])
			dfs(ny, nx, next, (dir+move[cur][(d+dir+4)%4][1])%4);
	}
}

int main () {
	for (int i=0; i<6; ++i) for (int j=0; j<6; ++j)
		scanf("%d", &b[i][j]);

	bool flag = false;
	for (int i=0; i<6; ++i){
		for (int j=0; j<6; ++j)
		if (b[i][j]) {
			dfs(i, j, 1, 0);
			flag = true;
			break;
		}
		if (flag) break;
	}

	int one;
	for (int i=1; i<=6; ++i) {
		if (ans[i] == 1) one = i;
		if (ans[i] == 0) {
			printf("0\n");
			return 0;
		}
	}

	int opposite[7] = {0, 3, 4, 1, 2, 6, 5};
	printf("%d\n", ans[opposite[one]]);


	return 0;
}



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

int b[5][5], cur[8][4], ans[8][4], best = 8;

int heuristic() {
	int ret = 0;
	bool r[5] ={}, c[5] = {};
	for (int i=0; i<4; ++i)
		for (int j=0; j<4; ++j) {
			int ii = (b[i][j]-1)/4, jj = (b[i][j]-1)%4;
			r[(ii-i+4)%4] = true, c[(jj-j+4)%4] =true;
		}
	for (int i=1; i<=4; ++i) {
		if (r[i]) ++ret;
		if (c[i]) ++ret;
	}
	return ret;
}

void push(int y, int x, int yy, int xx) {
	int temp = b[y][x]; 
	for (int i=0; i<4; ++i) {
		int ny = (y+yy)%4, nx = (x+xx)%4;
		int ttemp = b[ny][nx];
		b[ny][nx] = temp;
		temp = ttemp;
		y = ny, x= nx;
	}
}

void solve(int trial) {
	int est = heuristic();
	if (est == 0) {
		if (trial < best) {
			best = trial;
			for (int i=0; i<trial; ++i)
				for (int j=0; j<3; ++j)
					ans[i][j] = cur[i][j];
		}
		return;
	}

	if (trial + est >= best) return;

	for (int i=0; i<4; ++i) {
		for (int num=0; num<3; ++num) {
			push(i, 0, 0, 1);
			cur[trial][0] = 1, cur[trial][1] = i+1, cur[trial][2] = num+1;
			solve(trial+1);
		}
		push(i, 0, 0, 1);
		for (int num=0; num<3; ++num) {
			push(0, i, 1, 0);
			cur[trial][0] = 2, cur[trial][1] = i+1, cur[trial][2] = num+1;
			solve(trial+1);
		}
		push(0, i, 1, 0);
	}
}

int main () {
	for (int i=0; i<4; ++i)
		for (int j=0; j<4; ++j)
			scanf("%d", &b[i][j]);

	solve(0);

	printf("%d\n", best);
	for (int i=0; i<best; ++i)
		printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);

	return 0;
}



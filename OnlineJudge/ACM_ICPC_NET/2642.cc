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

const int dir[7][4] = {{}, {2, 5, 4, 6}, {3, 5, 1, 6}, {4, 5, 2, 6}, {1, 5, 3, 6}, {3, 4, 1, 2}, {3, 2, 1, 4}};

void dfs(int y, int x, int cur) {
	ans[cur] = board[y][x];
	for (int d=0; d<4; ++d)
int main () {
	
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j) scanf("%d", &b[i][j]);

	bool flag = false;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			if (b[i][j]) { dfs(i, j, 1); flag = true; break; }
		if (flag) break;
	}

	for (int i=1; i<=6; ++i)
		if (!ans[i]) { return printf("0\n"), 0; }

	printf("%d\n", ans[3]);
	return 0;
}



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

const int dy[4] = {0,0,1,-1}, dx[4] = {1,-1,0,0};
int n, b[101][101], v[101][101], best = INF;

void dfs(int y, int x, int to) {
	b[y][x] = to;
	for (int d=0; d<4; ++d) {
		int ny = y+dy[d], nx = x+dx[d];
		if (ny>=0 && nx>=0 && ny<n && nx<n && b[ny][nx] == 1)
			dfs(ny, nx, to);
	}
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j)
		scanf("%d", &b[i][j]);
	int cnt = 2;
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (b[i][j] == 1)
		dfs(i, j, cnt++);

	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (b[i][j] >= 2) {
		memset(v,0,sizeof(v));
		v[i][j] = 1;
		queue<pii> q; q.push(make_pair(i, j));
		while (!q.empty()) {
			int cy = q.front().first, cx = q.front().second; q.pop();
			int len = v[cy][cx];
			if (b[cy][cx] >= 2 && b[cy][cx] != b[i][j]) {
				best = min (best, len-2);
				break;
			}
	
			for (int d=0; d<4; ++d) {
				int ny = cy+dy[d], nx = cx+dx[d];
				if (ny>=0 && nx >= 0 && ny<n && nx<n && v[ny][nx] == 0 && b[ny][nx] != b[i][j]) {
					v[ny][nx] = len + 1;
					q.push(make_pair(ny, nx));
				}
			}
		}

	}

	printf("%d\n", best);
	return 0;
}



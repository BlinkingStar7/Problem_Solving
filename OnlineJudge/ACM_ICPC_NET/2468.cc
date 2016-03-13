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

const int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
int n, b[101][101], v[101][101], counter;

inline bool isSafe (int a, int b) { return (a>=0 && a<n) && (b>=0 && b<n); }
void dfs(int y, int x, int h) {
	v[y][x] = counter;
	for (int d=0; d<4; ++d) {
		int ny=y+dy[d], nx=x+dx[d];
		if (isSafe(ny, nx) && b[ny][nx] > h && v[ny][nx] != counter)
			dfs(ny, nx, h);
	}
}


int dfsAll(int h) {
	int ret = 0;
	++counter;

	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j)
		if (v[i][j] != counter && b[i][j] > h) {
			dfs(i, j, h);
			++ret;
		}
	return ret;
}


int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) scanf("%d", &b[i][j]);
	int ans = 1;
	for (int i=1; i<=100; ++i)
		ans = max(ans, dfsAll(i));

	printf("%d\n", ans);
	return 0;
}



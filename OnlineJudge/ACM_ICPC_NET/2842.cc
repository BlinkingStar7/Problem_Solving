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

char b[51][51];
int n, si, sj, cnt, hh[51][51], dy[8] = {0, 0, 1, 1, 1, -1, -1, -1}, dx[8] = {1, -1, -1, 0, 1, -1, 0, 1};
vi h;
bool v[51][51];

int dfs(int y, int x, int ll, int uu) {
	v[y][x] = true;
	if (hh[y][x] < ll || hh[y][x] > uu) return 0;
	int ret = b[y][x] == 'K';
	for (int d=0; d<8; ++d) {
		int ny = y+dy[d], nx = x+dx[d];
		if (ny>=0 && nx>=0 && ny<n && nx<n && !v[ny][nx])
			ret += dfs(ny, nx, ll, uu);
	}
	return ret;
}

int main () {
	scanf("%d ", &n);
	for (int i=0; i<n; ++i)
		gets(b[i]);

	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
		scanf("%d", &hh[i][j]);
		h.push_back(hh[i][j]);
		if (b[i][j] == 'P') {
			si = i, sj = j;
		}
		else if (b[i][j] == 'K')
			++cnt;
	}

	sort(h.begin(), h.end());
	h.erase(unique(h.begin(), h.end()), h.end());

	int lo=0, hi=0, ans=INF;
	while (1) {
		memset(v, 0, sizeof(v));
		if (dfs(si, sj, h[lo], h[hi]) == cnt) {
			ans = min(ans, h[hi] - h[lo]);
			++lo;
		}
		else if (++hi == h.size())
			 break;
	}
	printf("%d\n", ans);
	return 0;
}



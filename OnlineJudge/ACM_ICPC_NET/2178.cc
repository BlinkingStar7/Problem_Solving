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

int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
int main () {
	int n, m, b[101][101], v[101][101];
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; ++i) for (int j=0; j<m; ++j)
		scanf("%1d", &b[i][j]);
	memset(v, -1, sizeof(v));
	v[0][0] = 0;
	queue<pii> q;
	q.push(make_pair(0, 0));
	
	while(!q.empty()) {
		int ci=q.front().first, cj=q.front().second;
		q.pop();
		if (ci == n-1 && cj == m-1) {
			printf("%d\n", v[ci][cj]);
			return 0;
		}

		for (int d=0; d<4; ++d) {
			int ni=ci+di[d], nj=cj+dj[d];
			if (ni>=0&&ni<n&&nj>=0&&nj<m&&b[ni][nj]&&v[ni][nj]==-1) {
				v[ni][nj] = v[ci][cj] + 1;
				q.push(make_pair(ni, nj));
			}
		}
	}

	return 0;
}



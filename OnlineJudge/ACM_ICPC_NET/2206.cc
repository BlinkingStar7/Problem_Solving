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

struct p {
	int y, x, z;
};

const int dy[4] = {0,0,1,-1}, dx[4] = {1,-1,0,0};
int n,m,b[1001][1001],v[1001][1001][2];

int main () {
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) for (int j=0; j<m; ++j)
		scanf("%1d", &b[i][j]);

	v[0][0][0]= 1;

	queue<p> q; q.push((p){0, 0, 0});

	while (!q.empty()) {
		struct p cur = q.front();
		int y=cur.y, x=cur.x, z=cur.z, l=v[y][x][z];
		q.pop();

		if (y == n-1 && x == m-1) {
			printf("%d\n", l);
			return 0;
		}
		
		for (int d=0; d<4; ++d) {
			int ny=y+dy[d], nx=x+dx[d];
			if (ny>=0&&nx>=0&&ny<n&&nx<m&&v[ny][nx][z] == 0 && b[ny][nx] == 0) {
				q.push((p){ny,nx,z});
				v[ny][nx][z] = l+1;
			}
			if (ny>=0&&nx>=0&&ny<n&&nx<m&&z==0&&v[ny][nx][z+1] == 0 && b[ny][nx] == 1) {
				q.push((p){ny,nx,z+1});
				v[ny][nx][z+1] = l+1;
			}
		}
	}
	printf("-1\n");

	return 0;
}



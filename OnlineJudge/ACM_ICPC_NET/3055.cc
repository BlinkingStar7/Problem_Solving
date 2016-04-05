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

const int dy[4] = {0,0,1,-1}, dx[4]={1,-1,0,0};
int r, c, v[51][51];
char b[51][51];

bool isNext(int y, int x) {
	for (int d=0; d<4; ++d) {
		int ny = y +dy[d], nx = x+dx[d];
		if (ny>=0&&nx>=0&&ny<r&&nx<c&&b[ny][nx] == '*')
			return true;
	}
	return false;
}

int main () {
	scanf("%d%d ", &r,&c);
	int si, sj;
	for (int i=0; i<r; ++i) {
		for (int j=0; j<c; ++j) {
			scanf("%c", &b[i][j]);
			if (b[i][j] == 'S') {
				si = i; sj = j;
				b[i][j] = '.';
			}
		}
		getchar();
	}
	memset(v, -1, sizeof(v));
	v[si][sj] = 0;
	queue<pii> q; q.push(make_pair(si, sj));
	for (int t=1; ; ++t) {
		for (int i=0; i<r; ++i) for (int j=0; j<c; ++j) {
			if (b[i][j] == '.' && isNext(i, j)) b[i][j] = '$';
		}
		for (int i=0; i<r; ++i) for (int j=0; j<c; ++j)
			if (b[i][j] == '$') b[i][j] = '*';

		while (!q.empty()) {
			int ci=q.front().first, cj=q.front().second;
			if (v[ci][cj] != t-1) break;
			q.pop();
			if (b[ci][cj] == 'D') {
				printf("%d\n", v[ci][cj]);
				return 0;
			}

			for (int d=0; d<4; ++d) {
				int ny=ci+dy[d], nx=cj+dx[d];
				if (ny>=0&&nx>=0&&ny<r&&nx<c&&b[ny][nx] != '*'&&b[ny][nx] != 'X' && v[ny][nx] == -1) {
					v[ny][nx] = v[ci][cj]+1;
					q.push(make_pair(ny, nx));
				}
			}
		}
		if (q.empty()) {
			printf("KAKTUS\n");
			return 0;
		}
	}
	return 0;
}



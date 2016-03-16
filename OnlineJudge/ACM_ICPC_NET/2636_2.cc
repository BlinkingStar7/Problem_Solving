#include <cstdio>

int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1}, h, w, s[110][110], res;
bool inside(int a, int b) { return (0<=a && a<h) && (0<=b && b<w); }
int done() {
	int cnt = 0;
	for (int i=0; i<h; ++i) for (int j=0; j<w; ++j)
		if (s[i][j] == -1 || s[i][j] >= 2) s[i][j] = 0;
		else if (s[i][j] == 1)
			s[i][j] = 1, ++cnt;
	return cnt;
}

int solve(int a, int b) {
	s[a][b] = -1;
	for (int i=0; i<4; ++i) {
		int ny=a+dy[i], nx=b+dx[i];
		if (inside(ny, nx)) {
			if (s[ny][nx] == 0) solve(ny, nx);
			else if (s[ny][nx] > 0) ++s[ny][nx];
		}
	}
}

int main () {
	scanf("%d%d",&h,&w);
	for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) scanf("%d", &s[i][j]);
	int cur, bef;
	for (res=0; cur=done(); ++res){
		solve(0, 0);
		bef = cur;
	}

	printf("%d\n%d\n", res,bef);
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

int n, m, t, k, ans, ax, ay, d[101][2], x[101], y[101];

inline bool in(int yy, int xx) {
	int ty = yy-k/2, tx = xx-k/2;
	if (abs(ty)%2 != abs(tx)%2) return false;
	int cy = (ty-tx)/2, cx = (ty+tx)/2;
	return cy>=0 && cy<=m && cx>=0 && cx<=n;
}

int main () {
	scanf("%d%d%d%d", &n, &m, &t, &k);
	for (int i=0; i<t; ++i) {
		scanf("%d%d", &d[i][0], &d[i][1]);
		x[i] = d[i][0]-d[i][1]; y[i] = d[i][0]+d[i][1];
		d[i][0] = x[i], d[i][1] = y[i];
	}

	sort(x, x+t); sort(y, y+t);

	for (int i=0; i<t; ++i) for (int j=0; j<t; ++j) {
		int cnt = 0, xx=max(x[i],, yy=y[j];
		if (!in(yy, xx)) continue;
		for (int c=0; c<t; ++c)
			if (d[c][0] >= xx-k && d[c][0] <= xx && d[c][1] >= yy-k && d[c][1] <= yy) {
				++cnt;
			}
		if (cnt > ans ) {
			ans = cnt;
			ax = xx-k/2; ay = yy-k/2;
		}
	}
	int tx = ax, ty = ay;
	ax = (tx + ty)/2, ay = (ty - tx)/2;
	printf("%d %d\n", ax, ay);
	printf("%d\n", ans);

	return 0;
}



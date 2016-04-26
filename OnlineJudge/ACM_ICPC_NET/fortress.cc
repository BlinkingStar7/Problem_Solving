#include <bits/stdc++.h>
using namespace std;
int t, n, c[101][2], ans;
struct ff {
	int x, y, r;
	bool operator < (const ff& a) const {
		return r < a.r;
	}
} f[101];

inline bool isInside (int a, int b) {
	int xx = f[a].x - f[b].x, yy = f[a].y - f[b].y, rr = f[b].r - f[a].r;
	return xx*xx + yy*yy < rr*rr;
}

int main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(c, 0, sizeof(c));
		ans = 0;
	
		for (int i=0; i<n; ++i)
			scanf("%d%d%d", &f[i].x, &f[i].y, &f[i].r);

		sort(f, f+n);
		for (int i=0; i<n; ++i) {
			int ret = c[i][0]+1, cand = c[i][0] + c[i][1];
			if (cand > ans) 
				ans = cand;
			
			for (int j=i+1; j<n; ++j) {
				if (isInside(i, j)) {
					if (ret > c[j][0]) {
						c[j][1] = c[j][0];
						c[j][0] = ret;
					}
					else if (ret > c[j][1])
						c[j][1] = ret;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}



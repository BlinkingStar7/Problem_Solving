#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
	int r, c, n, cor[102];
	scanf("%d%d", &c, &r);
	scanf("%d", &n);

	for (int i=0; i<=n; ++i) {
		int d, p, pos;
		scanf("%d%d", &d, &p);
		if (d == 1) pos = p;
		if (d == 2) pos = 2*c + r - p;
		if (d == 3) pos = 2*c + 2*r - p;
		if (d == 4) pos = c + p;
		cor[i] = pos;
	}

	int ans=0;
	for (int i=0; i<n; ++i) {
		ans += min (abs(cor[n]- cor[i]), 2*r+2*c-abs(cor[n]-cor[i]));
	}

	printf("%d\n", ans);
	return 0;
}




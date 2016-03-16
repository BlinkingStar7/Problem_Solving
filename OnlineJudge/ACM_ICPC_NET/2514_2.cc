#include <cstdio>
int n, b[8][8], r[8] ,rr[8] , c[8] , cc[8] , ans[8][8];
int main() {
	scanf("%d%*d", &n);
	for (int i=0; i<8; ++i) for (int j=0; j<8; ++j) {
		scanf("%d", &b[i][j]); b[i][j] -= n;
		r[i] += b[i][j];
		c[j] += b[i][j];
	}
	for (int i=0; i<8; ++i) for (int j=0; j<8; ++j) {
		int sum = r[i] + c[j] - b[i][j];
		if (sum % 2) {
			ans[i][j] = 1;
			rr[i]++, cc[j]++;
		}
	}
	for (int i=0; i<8; ++i) r[i] = c[i] = 0;
	for (int i=0; i<8; ++i) for (int j=0; j<8; ++j) {
		b[i][j] -= rr[i] + cc[j] - ans[i][j];
		r[i] += b[i][j], c[j] += b[i][j];
	}
	for (int i=0; i<8; ++i) { for (int j=0; j<8; ++j) {
		int sum = r[i] + c[j] - b[i][j];
		if (ans[i][j]) {
			if (sum%4) putchar('-');
			else putchar('+');
		}
		else putchar('.');
		putchar(' ');
	}
	putchar('\n');
	}

	return 0;
} 

#include <cstdio>
#include <cstring>
typedef long long ll;
int const MOD = 1000000009;
int a[7][7] = {{},
	{1, 1, 0, 1, 1, 1, 0},
	{0, 1, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 1, 0}};
int b[7][7], c[7][7], n, k;

void m(int a[][7], int b[][7], int c[][7]) {
	for (int i=0; i<7; ++i)
		for (int j=0; j<7; ++j)
			for (int k=0; k<7; ++k)
				c[i][j] += (a[i][k] * b[k][j]) % MOD;
}

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0; i<7; ++i) {
		a[0][i] = k-2;
		b[i][i] = 1;
	}
	a[0][0] = k-1;

	while (n) {
		if (n&1) {
			memset(c, 0, sizeof(c));
			m(a, b, c);
			memcpy(b, c, sizeof(c));
		}
		n >>= 1;

		memset(c, 0, sizeof(c));
		m(b, b, c);
		memcpy(b, c, sizeof(a));
	}

	ll ans = 0;
	for (int i=0; i<7; ++i)
		ans = (ans + b[i][0])%MOD;
	printf("%lld\n", ans);
	return 0;
}



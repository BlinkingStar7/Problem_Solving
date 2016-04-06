#include <bits/stdc++.h>
using namespace std;
char a[100001], b[100001];
int memo[100001][2][2][3][2], aSize, bSize;
const int MOD = 20150523;

int solve (int cur, int sa, int sb, int r, int t) {
	if (cur == -1)
		return (r == 0 || t) ? 1 : 0;

	int &ret = memo[cur][sa][sb][r][t];
	if (ret != -1) return ret;

	ret = 0;
	int s = (cur >= aSize || !sa) ? '0' : a[cur];
	int e = sb ? b[cur] : '9';

	for (int i=s; i<=e; ++i) {
		int next = sa && (cur >= aSize ? i == '0' : a[cur] == i);
		ret = (ret + solve(cur-1, next , sb && b[cur] == i, (r+i-'0')%3, t || (i == '3' || i == '6' || i == '9'))) % MOD;
	}

	return ret;
}

int main () {
	scanf("%s %s", a, b);
	aSize = strlen(a), bSize = strlen(b);
	for (int i=0; i<aSize/2; ++i) swap(a[i], a[aSize-i-1]);
	for (int i=0; i<bSize/2; ++i) swap(b[i], b[bSize-i-1]);
	for (int i=aSize; i<bSize; ++i) a[i] = '0';

	memset(memo, -1, sizeof(memo));
	printf("%d\n", solve(bSize-1, 1, 1, 0, 0));
	return 0;
}



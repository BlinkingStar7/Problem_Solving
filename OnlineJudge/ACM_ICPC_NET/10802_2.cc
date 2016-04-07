#include <bits/stdc++.h>
using namespace std;
string str;
int memo[100001][2][3][2], boundary;
const int MOD = 20150523;

int solve (int cur, int same, int r, int t) {
	if (cur == str.size()) {
		if (same) boundary = (r == 0 || t);
		return r == 0 || t;
	}

	int &ret = memo[cur][same][r][t];
	if (ret != -1) return ret;

	ret = 0;
	for (int i=0; i<=(same? str[cur]-'0' : 9); ++i)
		ret = (ret + solve(cur+1, same && str[cur] == i+'0', (r+i)%3, t || i == 3 || i == 6 || i == 9))%MOD;
	return ret;
}

int main () {
	cin >> str;
	memset(memo, -1, sizeof(memo));
	int ans = -solve(0, 1, 0, 0);
	ans += boundary;
	cin >> str;
	memset(memo, -1, sizeof(memo));
	ans = (ans + solve(0, 1, 0, 0) + MOD) % MOD;
	printf("%d\n", ans);
	return 0;
}



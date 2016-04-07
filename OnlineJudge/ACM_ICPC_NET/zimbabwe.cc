#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
string str, s;
int m, memo[2][20][1<<15], d[16], t;
int solve (int same, int r, int set) {
	int cur = __builtin_popcount(set);
	if (cur == s.size()) return !same && r == 0;

	int &ret = memo[same][r][set];
	if (ret != -1) return ret;

	ret = 0;
	for (int i=0; i<s.size(); ++i) if (!(set & (1<<i))) {
		if (i == 0 || s[i] != s[i-1] || (set & (1<<(i-1)))) {
			char to = s[i];
			if (same && to > str[cur]) continue;
			ret = (ret + solve(same && to == str[cur], (r+(to-'0')*d[s.size()-cur-1])%m, set | (1<<i))) % MOD;
		}
	}
	return ret;
}


int main () {
	scanf("%d", &t);
	while (t--) {
		cin >> str >> m;
		s = str;
		d[0] = 1;
		for (int i=1; i<=15; ++i)
			d[i] = (d[i-1]*10)%m;
		sort(s.begin(), s.end());
		memset(memo, -1, sizeof(memo));
		printf("%d\n", solve(1, 0, 0));
	}
	return 0;
}



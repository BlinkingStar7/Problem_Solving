#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
using namespace std;

long long N, K, Memo[51][101][2];

long long Solve (long long n, long long open, bool normal) {
	if (n == 0) 
		return (open == 0) && normal ? 0 : 1;

	long long &ret = Memo[n][open + 50][normal];
	if (ret != -1) return ret;

	ret = 0;

	return ret = Solve(n-1, open+1, normal) + Solve(n-1, open-1, open>0 && normal);
}

void Reconstruct (int n, int open, bool normal) {
	if (n == 0) return;
	if (K > Solve(n-1, open+1, normal)) {
		putchar(')');
		K -= Solve(n-1, open+1, normal);
		return Reconstruct(n-1, open-1, open>0 && normal);
	}
	else {
		putchar('(');
		return Reconstruct(n-1,open+1, normal);
	}
}


int main () {
	memset(Memo, -1, sizeof(Memo));
	cin >> N >> K;

	++K;

	if (K > Solve (N, 0, true))
		cout << -1;
	else 
		Reconstruct(N, 0, true);
	puts("");

	return 0;
}


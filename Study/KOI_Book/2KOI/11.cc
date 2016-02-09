#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 1001
int A, B, S[3];
int memo[1001][1001];
int Solve(int l, int t) {
	if (l == B) return t;
	if (t > MAX) return MAX;

	int &ret = memo[l][t];
	if (ret != -1) return ret;
	
	ret = MAX;
	for (int i=0; i<3; ++i)
		ret = min (ret, Solve(l + S[i] * (l > B ? -1 : 1), t+1));
	
	return ret;
}

int main () {
	cin >> A >> B >> S[0] >> S[1] >> S[2];

	memset(memo, -1, sizeof(memo));

	int ret = Solve(A, 0);
	if (ret == MAX) cout << -1 << endl;
	else cout << ret << endl;
	return 0;
}


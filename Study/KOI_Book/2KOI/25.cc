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

string Key, Str[2];
int Memo[11][22][2];

int Solve (int p, int x, int t) {
	if (p == Key.size()) return 1;

	int &ret = Memo[p][x+1][t];
	if (ret != -1) return ret;

	ret = 0;

	for (int next = x+1; next<Str[t].size(); ++next)
		if (Str[t][next] == Key[p])
			ret += Solve (p+1, next, !t);

	return ret;
}

int main () {
	memset(Memo, -1, sizeof(Memo));
	cin >> Key >> Str[0] >> Str[1];
	cout << Solve(0, -1, 0) + Solve(0, -1, 1) << endl;
	return 0;
}


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
using namespace std;
#define MOD 1000000007

int C, M, Memo[1<<15][21][2];
string E, Digit;

int Solve (int select, int mod, int small, int n) {
	if (n == E.size())
		return mod == 0 && small ? 1 : 0;

	int &ret = Memo[select][mod][small];
	if (ret != -1) return ret;

	ret = 0;

	for (int next=E.size()-1; next>=0; --next) {
		if (((1 << next) & select) != 0) continue;
		int index = E.size()-1-next;
		if (!small && (Digit[index] > E[n])) continue;
		if (next==E.size()-1 || (1<<next+1 & select) != 0 || Digit[index] != Digit[index-1])
			ret = (ret + Solve (select | 1<<next, (mod*10+(Digit[index]-'0'))%M, small || Digit[index] < E[n], n+1))%MOD;
	}

	return ret;
}


int main () {
	cin >> C;

	while (C--) {
		cin >> E >> M;
		Digit = E;
		memset(Memo, -1, sizeof(Memo));
		sort(Digit.begin(), Digit.end());
		cout << Solve(0, 0, 0, 0) << endl;

	}


	return 0;
}


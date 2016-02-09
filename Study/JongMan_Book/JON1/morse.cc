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
#define MOD 1000000000

int C, N, M, K, Memo[101][101];

int Combi (int n, int m) {

	int &ret = Memo[n][m];
	if (ret != 0) return ret;

	if (n == 0 || m == 0) return ret = 1;
	ret = Combi(n-1, m) + Combi(n, m-1);
	if (ret > MOD) ret = MOD;
	return ret;
}

string Solve (int n, int m, int k){ 
	if (n==0) {
		string str = string (m, 'o');
		return str;
	}
	else if (m==0) {
		string str = string (n, '-');
		return str;
	}

	if (Combi (n-1, m) < k) return "o" + Solve (n, m-1, k - Combi(n-1, m));
	return "-" + Solve (n-1, m, k);
}


int main () {
	cin >> C;

	while (C--) {
		cin >> N >> M >> K;
		memset(Memo, 0, sizeof(Memo));

		cout << Solve (N, M, K) << endl;
	}


	return 0;
}


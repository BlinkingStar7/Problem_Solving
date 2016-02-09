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
#define MAX 987654321
int C, Memo[10001];
string P;

int Hard (int a, int b) {
	int dif = 0, notSame = 0;
	for (int i=a; i<b; ++i)
		if (P[i] - P[i+1] != P[a] - P[a+1]) {
			notSame = 1;
			break;
		}
	if (!notSame) {
		if (P[a+1] - P[a] == 0) return 1;
		else if (P[a+1] - P[a] == 1 || P[a+1] - P[a] == -1) return 2;
		else return 5;
	}

	for (int i=0; i<b-a+1; ++i)
		if (P[a+i] != P[a+i%2]) return 10;
	return 4;
}


int Solve (int p) {
	if (p == P.size()) return 0;

	int &ret = Memo[p];
	if (ret != -1) return ret;

	ret = MAX;

	for (int i=3; i<=5 && p+i <= P.size(); ++i)
		ret = min (ret, Hard(p, p+i-1) + Solve(p+i));
	return ret;
}

int main () {
	cin >> C;

	while (C--) {
		cin >> P;
		memset(Memo, -1, sizeof(Memo));

		cout << Solve(0) << endl;

	}


	return 0;
}


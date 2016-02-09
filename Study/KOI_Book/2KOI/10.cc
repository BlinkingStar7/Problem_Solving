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

int N, memo[50001];
int Solve(int n) {
	if (n < 10) return n;

	int &ret = memo[n];
	if (ret != -1) return ret;

	return ret = (n%10) * (int)pow(10, (int)log10(n)) + Solve(n/10);
}

int main () {
	memset(memo, -1, sizeof(memo));
	cin >> N;
	cout << Solve(N) << endl;

	return 0;
}


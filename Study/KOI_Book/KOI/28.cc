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
#define MAX 987654321

int memo[100][100], P, F, pl[100], fl[100];

int Solve (int f, int p) {
	if (f == F) return 0;
	if (p == P) return MAX;

	int &ret = memo[f][p];
	if (ret != -1) return ret;

	ret = MAX;

	for (int next=p; next<P; ++next)
		ret = min (ret, abs(fl[f] - pl[next]) + Solve (f+1, next+1));
	
	return ret;
}

int main () {
	cin >> P >> F;
	for (int i=0; i<P; ++i)
		cin >> pl[i];
	for (int i=0; i<F; ++i)
		cin >> fl[i];

	memset (memo, -1, sizeof(memo));
	cout << Solve (0, 0) << endl;
	return 0;
}


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 987654321;
int N, Memo[1001][4], Cost[1001][3];

int Solve (int pos, int bef) {
	if (pos == N) return 0;

	int &ret = Memo[pos][bef+1];
	if (ret != -1) return ret;

	ret = MAX;

	for (int next=0; next<3; ++next)
		if (bef != next)
			ret = min (ret, Cost[pos][next] + Solve(pos+1, next));
	return ret;
}

int main() {
	cin >> N;

	memset(Memo, -1, sizeof(Memo));
	for (int i=0; i<N; ++i)
		scanf("%d %d %d", &Cost[i][0], &Cost[i][1], &Cost[i][2]);
	cout << Solve(0, -1) << endl;

	return 0;
}



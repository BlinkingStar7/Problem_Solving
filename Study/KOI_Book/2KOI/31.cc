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

int D[11][11];
int Score [4][4] = {
	{100, 70, 40, 0},
	{70, 50, 30, 0},
	{40, 30, 20, 0},
	{0, 0, 0, 0}}, N, Memo[10][1<<11][1<<11];

int Solve (int r, int cur, int next) {
	if (r == N-1) return 0;

	int &ret = Memo[r][cur][next];
	if (ret != -1) return ret;

	ret = 0;

	for (int i=0; i<N-1; ++i)
		if (!(cur & 1<<i) && !(cur & 1<<(i+1)))  
			ret = max (ret, Score[D[r][i]][D[r][i+1]] + Solve(r, cur | 3<<i, next));
	for (int i=0; i<N-1; ++i)
		if (!(next & 1<<i) && !(next & 1<<(i+1)))  
			ret = max (ret, Score[D[r+1][i]][D[r+1][i+1]] + Solve(r, cur, next | 3<<i));
	for (int i=0; i<N; ++i)
		if (!(cur & 1<<i) && !(next & 1<<i))
			ret = max (ret, Score[D[r][i]][D[r+1][i]] + Solve(r, cur | 1<<i, next | 1<< i));

	return ret = max (ret, Solve(r+1, next, 0));
}

int main () {
	cin >> N;
	memset(Memo, -1, sizeof(Memo));

	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j) {
			char ch;
			scanf(" %c", &ch);
			if (ch == 'F')
				D[i][j] = 3;
			else
				D[i][j] = ch - 'A';
		}

	cout << Solve(0, 0, 0) << endl;
	return 0;
}


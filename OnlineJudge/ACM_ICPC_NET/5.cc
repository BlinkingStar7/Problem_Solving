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
#include <set>
using namespace std;

const int MIN = -987654321;
int N, Memo[3][501][501], A[501][501];

int Solve (int dir, int y, int x) {
	if (y<0 || x<0 || y>=N || x>=N) return MIN;
	if (y == N-1 && x == N-1) return A[N-1][N-1];
	int &ret = Memo[dir][y][x];
	if (ret != MIN) return ret;

	if (dir == 0 || dir == 1)
		ret = A[y][x] + max (Solve(0, y+1, x), Solve(1, y, x-1));
	if (dir == 0 || dir == 2)
		ret = max (ret, A[y][x] + max(Solve(0, y+1, x), Solve(2, y, x+1)));

	return ret;
}

int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j) {
			scanf("%d", &A[i][j]);
			Memo[0][i][j] = Memo[1][i][j] = Memo[2][i][j] = MIN;
		}


	cout << Solve (0, 0, 0) <<endl;

	return 0;
}


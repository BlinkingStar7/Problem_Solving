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
	{0, 0, 0, 0}}, N, Memo[11][11][1<<13];

#define cu (1<<N)
#define dn (1)
#define M (1<<(N+1))
#define rt (1<<(N-1))

int Solve (int y, int x, int chk) {
	if (y == N) return 0;
	if (x == N) return Solve(y+1, 0, chk);

	int &ret = Memo[y][x][chk];
	if (ret != -1) return ret;

	ret = 0;

	if (x != N-1 && !(chk&cu) && !(chk&rt)) {
		chk += (1 << N) + (1 << N-1);
		ret = max (ret, Score[D[y][x]][D[y][x+1]] + Solve(y, x+1, (chk<<1)%M));
		chk -= (1 << N) + (1 << N-1);
	}
	if (y != N-1 && !(chk & 1 << N) && !(chk & 1 << 0)) {
		chk += (1 << N) + 1;
		ret = max (ret, Score[D[y][x]][D[y+1][x]] + Solve(y, x+1, (chk<<1)%M));
		chk -= (1 << N) + 1;
	}
	return ret = max (ret, Solve(y, x+1, (chk<<1) & (1<<N+1) -1));
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


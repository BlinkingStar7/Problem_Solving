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

const int DY[4][3] = {{0, 1, 1}, {0, 1, 1}, {0, 0, 1}, {0, 0, 1}},
	  	 DX[4][3] = {{0, 0, -1}, {0, 0, 1}, {0, 1, 1}, {0, 1, 0}};

int C, H, W, A[21][21];

int Cover(int y, int x, int d, int c) {
	int ret = 1;
	for (int i=0; i<3; ++i) {
		int ny = y+DY[d][i], nx = x+DX[d][i];
		if ((ny<0||nx<0||ny>=H||nx>=W)) ret = 0;
		else {
			if (A[ny][nx]) ret = 0;
			A[ny][nx] += c;
		}
	}
	return ret;
}

int Solve(int y, int x) {
	if (x==W) return Solve(y+1, 0);
	if (y==H) return 1;
	if (A[y][x]) return Solve(y, x+1);

	int ret = 0;

	for (int i=0; i<4; ++i) {
		if (Cover(y, x, i, 1))
			ret += Solve(y, x+1);
		Cover(y, x, i, -1);
	}

	return ret;
}

int main () {
	cin >> C;

	while (C--) {
		cin >> H >> W;
		int num = 0;
		for (int i=0; i<H; ++i)
			for (int j=0; j<W; ++j) {
				char c;
				cin >> c;
				A[i][j] = (c == '#') ? 1 : 0;
				num += A[i][j];
			}
		if ((H*W - num) % 3 != 0) {
			cout << 0 << endl;
			continue;
		}

		cout << Solve(0, 0) << endl;
	}

	return 0;
}


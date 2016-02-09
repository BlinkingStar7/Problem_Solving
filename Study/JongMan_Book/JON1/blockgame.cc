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

int C, Board[6][6];

int State () {
	int ret =0;
	for (int i=0; i<5; ++i)
		for (int j=0; j<5; ++j) {
			ret *= 2;
			ret += Board[i][j];
		}
	return ret;
}

int CoverI (int y, int x, int d, int alpha) {
	int ret = 1;
	for (int k=0; k<2; ++k) {
		int ny = y + d
	int ret = 1;
	if (y>=5||x>=5||y<0||x<0) ret = 0;
	else {
		if (Board[y][x]) ret = 0;
		Board[y][x] += alpha;
	}

	if (num == 1) return ret;

	return ret

int Solve () {
	int &ret = Memo[State()];
	if (ret != -1) return ret;

	ret = 2;

	for (int i=0; i<5; ++i)
		for (int j=0; j<5; ++j) {
			if (Board[i][j] == 0) {
				for (int d=0; d<2; ++d) {
					if (CoverI(i, j, d, 2, 1))
						ret = min (ret, Solve());
					CoverI(i, j, d, 2, -1);
				}
				for (int d=0; d<4; ++d) {
					if (CoverL(i, j, d, 3, 1))
						ret = min (ret, Solve());
					CoverL(i, j, d, 3, -1);
				}
			}
		}
	if (ret == 2) return ret = 0;
	else return ret = 1 - ret;
}


int main () {
	cin >> C;

	while (C--) {
		for(int i=0; i<5; ++i) {
			cin.get();
			for (int j=0; j<5; ++j) {
				char temp;
				cin >> temp;
				if (temp == '.') Board[i][j] = 0;
				else Board[i][j] = 1;
			}
		}

		memset (Memo, -1, sizeof(Memo));

		if (Solve()) cout << "WINNING" << endl;
		else cout << "LOSING" << endl;


	}


	return 0;
}


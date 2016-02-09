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

int T, H, W, R, C, bestNum, Board[11][11], Block[11][11], Space[11][11];
vector<pair<int, int> > B[4];

void preCalBlock() {
	for (int i=0; i<4; ++i) {
		B[i].clear();
	}

	for (int i=0; i<R; ++i) {
		for (int j=0; j<C; ++j) {
			if (Block[i][j] == 1) {
				B[0].push_back(make_pair(i, j));
				B[1].push_back(make_pair(j, (R-1)-i));
				B[2].push_back(make_pair((R-1)-i, (C-1)-j));
				B[3].push_back(make_pair((C-1)-j, i));
			}
		}
	}
}

void preCalSpace () {
	memset(Space, 0, sizeof(Space));
	int space =0;
	for (int i=H-1; i>=0; --i)
		for (int j=W-1; j>=0; --j)
			Space[i][j] = Board[i][j] == 0 ? ++space: space;
}

int Cover(int y, int x, int s, int a) {
	int ret = 1;
	for (int i=0; i<B[s].size(); ++i) {
		int ny=y+B[s][i].first, nx=x+B[s][i].second;
		if (ny>=H||ny<0||nx>=W||nx<0) ret= 0;
		else {
			if (Board[ny][nx] == 1) ret = 0;
			Board[ny][nx] += a;
		}
	}
	return ret;
}


int Solve (int y, int x, int num) {
	if (y == H) {
		if (num > bestNum) bestNum = num;
		return 0;
	}
	if (x == W) return Solve (y+1, 0, num);
	if (Space[y][x]/B[0].size() + num <= bestNum) return 0;

	if (Space[y][x] <= 20) return num + dp (y, x);

	int ret = num;

	for (int block=0; block<4; ++block) {
		if (Cover(y, x, block, 1))
			ret = max(ret, 1 + Solve (y, x+1, num+1));
		Cover(y, x, block, -1);
	}
	return max(ret, Solve (y, x+1, num));
}


int main () {
	cin >> T;

	while (T--) {
		bestNum = 0;
		memset(Memo, -1, sizeof(Memo));
		cin >> H >> W >> R >> C;
		for (int i=0; i<H; ++i) {
			cin.get();
			for (int j=0; j<W; ++j) {
				char t;
				cin >> t;
				Board[i][j] = t == '#' ? 1 : 0;
			}
		}

		for (int i=0; i<R; ++i) {
			cin.get();
			for (int j=0; j<C; ++j) {
				char t;
				cin >> t;
				Block[i][j] = t == '#' ? 1 : 0;
			}
		}

		preCalBlock();
		preCalSpace();

	    cout << Solve(0, 0, 0) << endl;

	}


	return 0;
}


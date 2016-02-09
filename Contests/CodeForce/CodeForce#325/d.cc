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

const int 
dy[3][4] = {
	{0, 0, 0, 0},
	{0, -1, -1, -1},
	{0, 1, 1, 1}}, 
dx[3][4] = {
	{1, 1, 2, 3},
	{1, 1, 2, 3},
	{1, 1, 2, 3}};

int testNum, N, K, Memo[4][101];
char B[3][101];

int Solve (int y, int x) {
	if (x >= N) return 1;

	int &ret = Memo[y][x];
	if (ret != -1) return ret;

	ret = 0;

	for (int d=0; d<3; ++d) {
		int flag = 1;
		for (int i=0; i<4; ++i) {
			int ny=y+dy[d][i], nx=x+dx[d][i];
			if (nx >= N) return ret = 1;
			if (ny<0 || ny>=3 || B[ny][nx] != '.') {
				flag = 0;
				break;
			}
		}
		if (flag) ret = ret || Solve(y+dy[d][3], x+dx[d][3]);
	}

	return ret;
}


int main () {
	cin >> testNum;

	while (testNum--) {
		memset(B, 0, sizeof(B));
		memset(Memo, -1, sizeof(Memo));
		
		cin >> N >> K;

		int s=-1;

		for (int i=0; i<3; ++i)
			for (int j=0; j<N; ++j)
				cin >> B[i][j];

		for (int i=0; i<3; ++i)
			if (B[i][0] == 's') s=i;

		if (Solve(s, 0)) cout << "YES" << endl;
		else cout << "NO" << endl;

	}


	return 0;
}


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

int C, N, Memo[6][6][11];
char A[6][6], str[11];
const int DX[8] = {0, 1, 1, 1, 0, -1, -1, -1}, 
	  	  DY[8] = {1, 1, 0, -1, -1, -1, 0, 1};

bool isSafe (int y, int x) { return x>=0&&y>=0&&x<5&&y<5; }
int Solve (int y, int x, int p) {
	if (str[p] == '\0') return 1;
	if (str[p] != A[y][x]) return 0;
	

	int &ret = Memo[y][x][p];
	if (ret != -1) return ret;

	ret = 0;

	for (int i=0; i<8; ++i) {
		int ny=y+DY[i], nx=x+DX[i];
		if (isSafe(ny, nx))
			ret = ret || Solve (ny, nx, p+1);
	}

	return ret;
}

int main () {

	cin >> C;
	while (C--) {
		for (int i=0; i<5; ++i)
			cin >> A[i];

		cin >> N;
		for (int i=0; i<N; ++i) {
			cin >> str;
			memset(Memo, -1, sizeof(Memo));
			int flag = 0;
			for (int x=0; x<5; ++x) {
				for (int y=0; y<5; ++y)
					if (Solve(y, x, 0)) {
						flag = 1;
						printf("%s YES\n", str);
						break;
					}
				if (flag) break;
			}
			if (!flag) printf("%s NO\n", str);
		}
	
	}
	return 0;
}



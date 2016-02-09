#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
using namespace std;

const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int C, R, K, Seat[1001][1001];

pair<int, int> Solve(int x, int y, int cnt, int d) {
	Seat[y][x] = cnt;
	if (cnt == K) return make_pair(x, y);

	int nx = x+dx[d], ny = y+dy[d];
	if (nx<=0||ny<=0||nx>C||ny>R||Seat[ny][nx]) {
		d = (d+1)%4;
		int nnx = x+dx[d], nny = y+dy[d];
		return Solve(nnx, nny, cnt+1, d);
	}
	return Solve(nx, ny, cnt+1, d);
}


int main () {
	cin >> C >> R >> K;

	if (K > C*R) {
		printf("0\n");
		return 0;
	}

	pair<int, int> ret = Solve (1, 1, 1, 0);
	printf("%d %d\n", ret.first, ret.second);
	
	return 0;
}


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

int M, N, H, Box[101][101][101];
const int dirx[6] = {0, 1, 0, -1, 0, 0},
diry[6] = {-1, 0, 1, 0, 0, 0},
dirz[6] = {0, 0, 0, 0, 1, -1};

struct point {
	int x, y, z;
};

bool isSafe (int x, int y, int z) {
	return x>=0&&y>=0&&z>=0&&x<M&&y<N&&z<H;
}

int bfs() {
	queue<point> q;
	for (int i=0; i<H; ++i)
		for (int j=0; j<N; ++j)
			for (int k=0; k<M; ++k)
				if (Box[k][j][i] == 1)
					q.push((point){k, j, i});
	
	while (!q.empty()) {
		point here = q.front(); q.pop();
		int cost = Box[here.x][here.y][here.z];

		for (int d=0; d<6; ++d) {
			int nx = here.x + dirx[d];
			int ny = here.y + diry[d];
			int nz = here.z + dirz[d];
			if (isSafe(nx, ny, nz) && Box[nx][ny][nz] == 0) {
				Box[nx][ny][nz] = cost+1;
				q.push((point){nx, ny, nz});
			}
		}
	}

	int ret = 0;
	for (int i=0; i<H; ++i)
		for (int j=0; j<N; ++j)
			for (int k=0; k<M; ++k)
				if (Box[k][j][i] == 0) return -1;
				else ret = max(ret, Box[k][j][i]);
	return ret-1;
}

	
int main () {
	cin >> M >> N >> H;
	for (int z=0; z<H; ++z)
		for (int y=0; y<N; ++y)
			for (int x=0; x<M; ++x)
				scanf("%d", &Box[x][y][z]);

	cout << bfs() << endl;

	return 0;
}


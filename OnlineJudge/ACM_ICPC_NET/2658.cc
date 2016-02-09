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

int Board[20][20];
bool Visited[20][20];
const int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

bool dfs(int y, int x) {
	if (Board[y][x] == 0) return false;

	bool ret = true;

	Visited[y][x] = true;
	for (int d=0; d<4; ++d) {
		int ny = y+dy[d], nx = x+dx[d];
		if (Board[ny][nx] == 1 && !Visited[ny][nx])
			ret = ret && dfs(ny, nx);
	}
	return ret;
}
void fail() {
	printf("0\n");
	exit(0);
}

void debug () {
	for (int i=1; i<=10; ++i) {
		for (int j=1; j<=10; ++j) 
			printf("%d",Board[i][j]);
		printf("\n");
	}
}

void RotateClockwise() {
	int newBoard[20][20] ={};
	for (int i=1; i<=10; ++i)
		for (int j=1; j<=10; ++j) {
			newBoard[j][11-i] = Board[i][j];
		}

	for (int i=1; i<=10; ++i)
		for (int j=1; j<=10; ++j)
			Board[i][j] = newBoard[i][j];
}

int main () {
	for (int i=1; i<=10; ++i)
		for (int j=1; j<=10; ++j)
			scanf("%1d", &Board[i][j]);

	int num = 0;

	for (int i=1; i<=10; ++i)
		for (int j=1; j<=10; ++j) {
			if (Board[i][j] == 1 && !Visited[i][j]) {
				++num;
				dfs(i, j);
			}
		}
	if (num != 1)
		fail();

	for (int i=1; i<=10; ++i)
		for (int j=1; j<=10; ++j) {
			if (Board[i][j] == 1) {
				bool flag = false;
				for (int d=0; d<4; ++d) {
					int ny=i+dy[d], nx=j+dx[d];
					if (Board[ny][nx] == 0)
						flag = true;
				}
				if (flag) Board[i][j] = 2;
			}
		}


	for (int i=1; i<=10; ++i) {
		bool met2 = false, met0 = false;
		for (int j=1; j<=10; ++j) {
			if (Board[i][j] == 2) {
				met2 = true;
				if (met0) fail();
			}
			else if (Board[i][j] == 0) {
				if (met2) met0 = true;
			}
		}
	}

	for (int r=0; r<4; ++r) {
		RotateClockwise();
		for (int d=0; d<2; ++d) {
			bool flag = false;
			for (int i=1; i<=10; ++i) {
				for (int j=1; j<=10; ++j) {
					if (d == 0) {
						if (Board[i][j] != 0) {
							Board[i][j] = 3;
							flag = true;
							break;
						}
					}
					else {
						if (Board[i][11-j] != 0) {
							Board[i][11-j] = 3;
							flag = true;
							break;
						}
					}
				}
				if (flag) break;
			}
		}
	}

#ifdef DEBUG
	debug();
#endif

	vector<pair<int, int> > vertex;
	for (int i=1; i<=10; ++i) {
		for (int j=1; j<=10; ++j) { 
			if (Board[i][j] == 3) 
				vertex.push_back(make_pair(i, j));
		}
	}
	if (vertex.size()!=3) fail();

	sort (vertex.begin(), vertex.end());

	for (int i=0; i<3; ++i) {
		pair<int, int> p1 = vertex[i%3], p2 = vertex[(i+1)%3];
		int ydiff = p2.first - p1.first, xdiff = p2.second - p1.second;
		if (xdiff == 0 || ydiff == 0 || abs(xdiff) == abs(ydiff)) {
			int len = max(abs(xdiff), abs(ydiff));
			for (int j=0; j<=len; ++j) {
				int y = p1.first + j*(ydiff/len);
				int x = p1.second + j*(xdiff/len);
				if (Board[y][x] != 2 && Board[y][x] != 3)
					fail();
			}
		}
		else fail();
	}

	for (int i=0; i<3; ++i)
		printf("%d %d\n", vertex[i].first, vertex[i].second);

	return 0;
}


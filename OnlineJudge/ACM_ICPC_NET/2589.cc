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

int testNum, R, C;
bool Water[51][51];
int Visited[51][51]; 
const int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int bfs(int yy, int xx) {
	queue<pair<int, int> > q;
	q.push(make_pair(yy, xx));
	Visited[yy][xx] = 1;
	int ret = 0;

	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		int y=p.first, x=p.second, dist=Visited[y][x];
		ret = max (ret, dist);
		for (int d=0; d<4; ++d) {
			int ny=y+dy[d], nx=x+dx[d];
			if (ny>=0&&nx>=0&&ny<R&&nx<C&&!Water[ny][nx]&&!Visited[ny][nx]) {
				q.push(make_pair(ny, nx));
				Visited[ny][nx] = dist+1;
			}
		}
	}
	return ret;
}

int bfsAll() {
	int ret = 0;

	for (int i=0; i<R; ++i)
		for (int j=0; j<C; ++j) {
			if (!Water[i][j]) {
				memset(Visited, 0, sizeof(Visited));
				ret = max (ret, bfs(i, j));
			}
		}
	return ret;
}

				


int main () {
	cin >> R >> C;
	for (int i=0; i<R; ++i) 
		for (int j=0; j<C; ++j) {
			char c;
			scanf(" %c", &c);
			Water[i][j] = c == 'W' ? 1 : 0;
		}

	cout << bfsAll() - 1 << endl;
	return 0;
}


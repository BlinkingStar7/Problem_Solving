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

const int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
int Board[66][66], N;
double ans = 0.0;

inline void fill (int x, int y, int xx, int yy) {
	for (int i=y; i<=yy; ++i) 
		for (int j=x; j<=xx; ++j)
			Board[i][j] = 1;
}
void debug() {
#ifdef DEBUG
	printf("%.2lf\n", ans);
	for (int i=51; i>=0; --i) {
		for (int j=0; j<52; ++j)
			printf("%2d",Board[i][j]);
		puts("");
	}
#endif
}
void dfs (int y, int x,int from, int to) {
	if (y<0 || x<0 || y>=52 || x>=52 || Board[y][x] != from) return;
	Board[y][x] = to;

	for (int d=0; d<4; ++d) {
		int ny = y +dy[d], nx = x+dx[d];
		dfs (ny, nx, from, to);
	}
}

void constructBoard (vector<pair<int, int> >& point) {
	for (int i=0; i<N; ++i) {
		int xdiff = point[i+1].first - point[i].first;
		int ydiff = point[i+1].second - point[i].second;

		if (xdiff == 0) {
			int x = point[i].first -1;
			if (ydiff > 0) fill (x, point[i].second, x, point[i+1].second-1);
			else fill(x+1, point[i+1].second, x+1, point[i].second-1);
		}
		else {
			int y = point[i].second-1;
			if (xdiff > 0) fill (point[i].first,y+1, point[i+1].first-1, y+1);
			else fill (point[i+1].first, y, point[i].first-1, y);
		}
	}

	dfs (51, 51, 0, -1);
	for (int i=0; i<52; ++i)
		for (int j=0; j<52; ++j)
			if (Board[i][j] != -1) Board[i][j] = 1;
	dfs (51, 51, -1, 0);

}

void cw() {
	int newBoard[52][52];
	for (int i=0; i<52; ++i)
		for (int j=0; j<52; ++j)
			newBoard[51-j][i] = Board[i][j];

	for (int i=0; i<52; ++i)
		for (int j=0; j<52; ++j)
			Board[i][j] = newBoard[i][j];
}

int dfsl (int limit, int y, int x, int from, int to, bool right) {
	if (y<0||x<0||y>=52||x>=52||Board[y][x] != from) return 0;
	if (right) {
		if (x < limit) return 0;
	}
	else {
		if (x >= limit) return 0;
	}

	int ret = 1;
	Board[y][x] = to;
	for (int d=0; d<4; ++d) {
		int ny=y+dy[d], nx=x+dx[d];
		ret += dfsl (limit, ny, nx, from, to, right);
	}
	return ret;
}

void mySolve(int len, int l, int y, int x, int from, int to, bool right) {
	int ret = dfsl(l, y, x, from, to, right);
	debug();
	if (Board[0][0] != -1 && Board[51][51] != -1)
		ans = max (ans, (double)(ret)/len);

	dfsl(l, y, x, to, from, right);
}

void Solve() {

	for (int x=1; x<=50; ++x) {
		vector<pair<int, int> > cand;
		for (int y=0; y<=51; ++y) {
			if (Board[y][x] == 1) {
				int start = y;
				while (Board[y][x] == 1)
					++y;
				cand.push_back(make_pair(start, y-1));
			}
		}

		for (int i=0; i<(int)cand.size()-1; ++i) {
			int start = cand[i].second+1, end = cand[i+1].first-1;
			mySolve(end-start+1,x, start, x, 0, -1, true);
			mySolve(end-start+1,x+1,start,x, 0, -1, true);
			mySolve(end-start+1,x, start, x-1, 0, -1, false);
			mySolve(end-start+1,x+1,start,x-1, 0, -1, false);

		}
	}
}

int main () {
	cin >> N;
	vector<pair<int, int> > point(N+1);
	for (int i=0; i<N; ++i) {
		scanf("%d%d", &point[i].first, &point[i].second);
		point[i].first += 1;
		point[i].second+= 1;
	}
	point[N] = point[0];

	constructBoard (point);
	Solve();
	cw();
	Solve();

	printf("%.2lf\n", ans);

	return 0;
}


#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 100

int cnt = -1, map[MAXN+2][MAXN+2], visit[MAXN+2][MAXN+2], N, M;
int isSafe(int y, int x) { return y>=0 && x>=0 && y <=N+1 && x <=M+1;}
const int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};


void dfs (int y, int x) {
	for (int d=0; d<4; ++d) {
		int ny = y+dy[d], nx = x+dx[d];
		if (isSafe (ny, nx) && !visit[ny][nx] && map[ny][nx] == 0) {
			map[ny][nx] = 2;
			visit[ny][nx] = 1;
			dfs (ny, nx);
		}
	}
}
void Cover() {
	memset (visit, 0, sizeof(visit));
	dfs (0, 0);
}

void Mark() {
	for (int i=1; i<=N; ++i) {
		for (int j=1; j<=M; ++j) {
			if (map[i][j] == 1) {
			int c=0;
			for (int d=0; d<4; ++d)
				if (map[i+dy[d]][j+dx[d]] == 2)
					++c;
			if (c >= 2)
				map[i][j] = -1;
			}
		}
	}
}

void Remove () {
	for (int i=1; i<=N; ++i) 
		for (int j=1; j<=M; ++j) {
			if (map[i][j] == -1) map[i][j] = 2;
		}
}


int isEnd() {
	cnt ++;
	for (int i=1; i<=N; ++i)
		for (int j=1; j<=M; ++j)
			if (map[i][j] != 2) 
				return 0;
	return 1;
}

int main() {
	cin >> N >> M;
	for (int i=1; i<=N; ++i)
		for (int j=1; j<=M; ++j)
			cin >> map[i][j];
	Cover();
	while (!isEnd()) {
		Mark();
		Remove();
		Cover();
	}
	cout << cnt << endl;
	return 0;
}



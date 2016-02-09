#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) ;
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int R,C,M,N,W, board[101][101], odd, even;
bool visited[101][101];
const int dy[8] = {1,1,1,1,-1,-1,-1,-1},
		  dx[8] = {1,1,-1,-1,1,1,-1,-1};
inline bool isSafe(int y, int x) {return y>=0&&x>=0&&y<R&&x<C; }
void solve(int y, int x) {
	visited[y][x] = true;
	DPRINTF(("(%d, %d) visited\n", y, x));
	vpii cand;

	for (int d=0; d<8; ++d) {
		int ny = y + dy[d]*(d%2 ? M : N); 
		int nx = x + dx[d]*(d%2 ? N : M);

		if (isSafe(ny, nx) && board[ny][nx] != -1)
			cand.push_back(make_pair(ny, nx));
	}

	sort(cand.begin(), cand.end());
	cand.erase(unique(cand.begin(), cand.end()), cand.end());

	cand.size()%2 ? ++odd : ++even;

	for (int i=0; i<(int)cand.size(); ++i) {
		if (!visited[cand[i].first][cand[i].second])
			solve(cand[i].first, cand[i].second);
	}
}

int main () {
	int t;
	scanf("%d", &t);
	for (int tt=1; tt<=t; ++tt) {
		memset(board, 0, sizeof(board));
		memset(visited, 0, sizeof(visited));
		odd = even = 0;

		scanf("%d%d%d%d%d", &R,&C,&M,&N,&W);
		for (int i=0; i<W; ++i) {
			int x, y;
			scanf("%d%d",&x,&y);
			board[x][y] = -1;
		}

		for (int i=0; i<R; ++i) {
			for (int j=0; j<C; ++j)
				DPRINTF(("%d",board[i][j]));
			DPRINTF(("\n"));
		}
		solve(0, 0);
		
		printf("Case %d: %d %d\n", tt, even, odd);
	}
	return 0;
}



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

int board[810][210], H, W, white[55];
bool visited[55];
string toLetter = "*WAKJSD";
const int dy[4] = {0,-1,0,1}, dx[4] = {1,0,-1,0};

inline bool isSafe(int y, int x) {return y>=0 && x>=0 && y<=H+1 && x<=W+1;}
void dfs(int y, int x, int from, int to, bool flag) {
	board[y][x] = to;

	for (int d=0; d<4; ++d) {
		int ny=y+dy[d], nx=x+dx[d];
		if (isSafe(ny, nx)) {
			if (board[ny][nx] == from) dfs(ny, nx, from, to, flag);
			else if (flag && board[ny][nx] != 0 && board[ny][nx] != -1) {
				if (!visited[board[ny][nx]]) {
					visited[board[ny][nx]] = true;
					++white[board[ny][nx]];
				}
			}
		}
	}
}

int main () {
	int tt = 1;	
	while (scanf("%d%d", &H, &W) != EOF && (H || W)) {
		memset(board, 0, sizeof(board));
		for (int i=1; i<=H; ++i)
			for (int j=0; j<W; ++j) {
				int x;
				scanf("%1x", &x);
				if (x == 0) continue;
				for (int k=0; k<4; ++k, x>>=1)
					board[i][4*j+4-k] = x&1;
			}
		
		W *= 4;
		

		int cnt = 2;
		memset(white, 0, sizeof(white));
		for (int i=1; i<=H; ++i) for (int j=1; j<=W; ++j)
			if (board[i][j] == 1) dfs(i, j, 1, cnt++, false);

		for (int i=1; i<=H; ++i) for (int j=1; j<=W; ++j)
			if (board[i][j] == 0) {
				memset(visited, false, sizeof(visited));
				dfs(i, j, 0, -1, true);
			}

		printf("Case %d: ",tt++);
		string ans;
		for (int i=2; i<cnt; ++i)
			ans += string(1, toLetter[white[i]]);
		sort(ans.begin(), ans.end());
		cout << ans << endl;
		
	}
	return 0;
}



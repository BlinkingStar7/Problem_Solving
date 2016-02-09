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

vector<vi > board;
string solve(int size, int y, int x) {
	bool flag = true;
	for (int i=0; i<size; ++i) {
		for (int j=0; j<size; ++j) {
			if (board[y][x] != board[y+i][x+j]) {
				flag = false;
				break;
			}
		}
	}

	if (flag) return string(1,'0'+ board[y][x]);
	return "(" + solve(size/2, y, x) + solve(size/2, y, x+size/2) + solve(size/2, y+size/2, x) + solve(size/2, y+size/2, x+size/2) + ")";
}

int main () {
	int size;
	scanf("%d", &size);

	board.assign(size, vi (size));
	for (int i=0; i<size; ++i)
		for (int j=0; j<size; ++j)
			scanf("%1d", &board[i][j]);

	cout << solve(size, 0, 0) << endl;
	return 0;
}



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
#include <set>
using namespace std;

int testNum, H, W, R, C, Space[11][11], bestNum=0;
vector<vector<int> > Board, Block;
vector<vector<pair<int, int> > > Pos;

vector<vector<int> > rotateBoard(vector<vector<int> >& board) {
	vector<vector<int> > ret(board[0].size());

	for (int i=board.size()-1; i>=0; --i) {
		for (int j=0; j<board[i].size(); ++j) {
			ret[j].push_back(board[i][j]);
		}
	}

	return ret;
}

void preCalcBlock() {
	vector<vector<int> > b = Block;
	
	for (int shape=0; shape<4; ++shape) {
		vector<pair<int, int> > t;
		int fy=-1, fx=-1;
		for (int i=0; i<b.size(); ++i) {
			for (int j=0; j<b[i].size(); ++j) {
				if (b[i][j] == 1) {
					if (fy == -1) {
						fy = i, fx = j;
						t.push_back(make_pair(0, 0));
					}
					else
						t.push_back(make_pair(i-fy, j-fx));
				}
			}
		}
		sort (t.begin(), t.end());
		Pos.push_back(t);
		b = rotateBoard(b);
	}

	for (int shape=3; shape>0; --shape) {
		for (int cand=0; cand<shape; ++cand)
			if (Pos[shape] == Pos[cand]) 
				Pos.erase(Pos.begin()+shape);
	}
}

void preCalcSpace() {
	int space = 0;

	for (int i=H-1; i>=0; --i)
		for (int j=W-1; j>=0; --j) {
			if (Board[i][j] == 0)
				++space;
			Space[i][j] = space;
		}
}

int Cover(int y, int x, int shape, int num) {
	int ret=1;

	for (int i=0; i<Pos[shape].size(); ++i) {
		int ny=y+Pos[shape][i].first, nx=x+Pos[shape][i].second;

		if (ny>=H||nx>=W||ny<0||nx<0) return 0;
		else {
			if (Board[ny][nx] == 1) ret = 0;
			Board[ny][nx] += num;
		}
	}
	return ret;
}

int Solve(int y, int x, int num) {
	if (y == H) {
		if (num > bestNum) bestNum = num;
		return num;
	}
	else if (x == W) return Solve(y+1, 0, num);

	if (Space[y][x] / Pos[0].size() + num <= bestNum) return 0;
	if (Board[y][x] == 1) return Solve (y, x+1, num);

	int cand = 0;

	for(int shape=0; shape<Pos.size(); ++shape) {
		if (Cover(y, x, shape, 1))
			cand = max (cand, Solve(y, x+1, num+1));
		Cover(y, x, shape, -1);
	}

	return max (cand, Solve(y, x+1, num));
}

int main () {
	cin >> testNum;

	while (testNum--) {
		Board.clear(), Block.clear(), Pos.clear();
		bestNum = 0;
		cin >> H >> W >> R >> C;
		for (int i=0; i<H; ++i) {
			cin.get();
			vector<int> row;
			for (int j=0; j<W; ++j) {
				char T;
				cin >> T;
				if (T == '#') row.push_back(1);
				else row.push_back(0);
			}
			Board.push_back(row);
		}

		for (int i=0; i<R; ++i) {
			cin.get();
			vector<int> row;
			for (int j=0; j<C; ++j) {
				char T;
				cin >> T;
				if (T == '#') row.push_back(1);
				else row.push_back(0);
			}
			Block.push_back(row);
		}

		preCalcBlock();
		preCalcSpace();
		/*
		for (int i=0; i<Pos.size(); ++i) {
			printf("Shape %d : ",i);
			for (int j=0; j<Pos[i].size(); ++j)
				printf("(%d, %d) ", Pos[i][j].first, Pos[i][j].second);
			cout << endl;
		}
		*/
		cout << Solve(0, 0, 0) << endl;

	}


	return 0;
}


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

int testNum, N, Blank[21][21], Q, Board[21][21], Find;
pair<int, int> Hint[21][21];

void Solve (int y, int x) {
	if (Find) return;
	if (y==N) {
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				printf("%s%d%s", j==0 ? "" : " ", Board[i][j], j==N-1 ? "\n" : "");
		Find = 1;
		return;
	}
	if (x==N) return Solve (y+1, 0);
	if (Blank[y][x] == 0) return Solve (y, x+1);

	int chk[11], upHint, leftHint, upSum=0, leftSum=0;
	memset(chk, 0, sizeof(chk));

	for (int i=y-1; i>=0; --i) {
		if (Blank[i][x] == 0) {
			upHint = Hint[i][x].first;
			break;
		}
		chk[Board[i][x]] = 1;
		upSum += Board[i][x];
	}
	for (int j=x-1; j>=0; --j) {
		if (Blank[y][j] == 0) {
			leftHint = Hint[y][j].second;
			break;
		}
		chk[Board[y][j]] = 1;
		leftSum += Board[y][j];
	}

	if (x+1==N || Blank[y][x+1] == 0) {// right end
		int here = -1;
		for (int cand=1; cand<=9; ++cand)
			if (chk[cand]==0 && leftSum + cand == leftHint) {
				here = cand;
				break;
			}
		if (here == -1) return;
		if (y+1==N || Blank[y+1][x] == 0) {// down end
			int here2 = -1;
			for (int cand=1; cand<=9; ++cand)
				if (chk[cand]==0 && upSum + cand == upHint) {
					here2 = cand;
					break;
				}
			if (here2 == -1 || here2 != here) return;
		}
		Board[y][x] = here;
		Solve(y, x+1);
		Board[y][x] = 0;
	}
	else if (y+1==N || Blank[y+1][x] == 0) {// down end
		int here = -1;
		for (int cand=1; cand<=9; ++cand)
			if (chk[cand]==0 && upSum + cand == upHint) {
				here = cand;
				break;
			}
		if (here == -1) return;
		Board[y][x] = here;
		Solve(y, x+1);
		Board[y][x] = 0;
	}
	else {
		for (int cand=1; cand<=9; ++cand)
			if (chk[cand]==0 && upSum + cand < upHint && leftSum + cand < leftHint) {
				Board[y][x] = cand;
				Solve(y, x+1);
				Board[y][x] = 0;
			}
	}
}

int main () {
	cin >> testNum;

	while (testNum--) {
		Find = 0;
		cin >> N;
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				cin >> Blank[i][j];
		cin >> Q;
		for (int i=0; i<Q; ++i) {
			int y, x, dir, sum;
			cin >> y >> x >> dir >> sum;
			if (dir == 0) Hint[y-1][x-1].second = sum;
			else Hint[y-1][x-1].first = sum;
		}

		Solve (0, 0);
	}


	return 0;
}


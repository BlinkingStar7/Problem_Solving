#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int N, M;
char Board[101][101];
const int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void Solve() {
	for (int i=0; i<N; ++i) {
		for (int j=0; j<M; ++j) {
			if (Board[i][j] == '*') {
				for (int d=0; d<8; ++d) {
					int ii = i+di[d], jj = j+dj[d];
					if (ii>=0&&jj>=0&&ii<N&&jj<M&&Board[ii][jj]!='*')
						++Board[ii][jj];
				}
			}
		}
	}
}

int main() {
	int num = 1;
	while (1) {
		scanf("%d %d", &N, &M);
		if (N == 0) break;

		for (int i=0; i<N; ++i) {
			for (int j=0; j<M; ++j) {
				scanf(" %c", &Board[i][j]);
				Board[i][j] = Board[i][j] == '.' ? '0' : '*';
			}
		}

		Solve();

		if (num >= 2) puts("");
		printf("Field #%d:\n", num++);
		for (int i=0; i<N; ++i) {
			for (int j=0; j<M; ++j)
				printf("%c", Board[i][j]);
			printf("\n");
		}
	}

	return 0;
}



#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;


const int dx[4] = {1,0,-1,0}, dy[4] = {0,-1,0,1};
char Board[251][251];
	int M, N;

void Cover (int x, int y, char c, char ori) {
	if (y<0||x<0||y>=N||x>=M) return;
	if (Board[y][x] == ori) {
		Board[y][x] = c;
		for (int i=0; i<4; ++i) {
			int nx=x+dx[i], ny=y+dy[i];
			Cover (nx, ny, c, ori);
		}
	}
}			

int main() {
	char op;
	while (1) {
		scanf(" %c", &op);
		if (op == 'X') break;
		if (op == 'I') {
			cin >> M >> N;
			for (int y=0; y<N; ++y)
				for (int x=0; x<M; ++x)
					Board[y][x] = 'O';
		}
		else if (op == 'C')
			memset(Board, 'O', sizeof(Board));
		else if (op == 'L') {
			int x, y;
			char c;
			scanf("%d %d %c", &x, &y, &c);
			Board[y-1][x-1] = c;
		}
		else if (op == 'V') {
			int x, y1, y2, c;
			scanf("%d %d %d %c", &x, &y1, &y2, &c);
			--x, --y1, --y2;
			for (int y=y1; y<=y2; ++y)
				Board[y][x] = c;
		}
		else if (op == 'H') {
			int x1, x2, y, c;
			scanf("%d %d %d %c", &x1, &x2, &y, &c);
			--x1, --x2, --y;
			for (int x=x1; x<=x2; ++x)
				Board[y][x] = c;
		}
		else if (op == 'K') {
			int x1, y1, x2, y2, c;
			scanf("%d %d %d %d %c", &x1, &y1, &x2, &y2, &c);
			--x1, --y1, --x2, --y2;
			for (int y=y1; y<=y2; ++y)
				for (int x=x1; x<=x2; ++x)
					Board[y][x] = c;
		}
		else if (op == 'F') {
			int x, y, c;
			scanf("%d %d %c", &x, &y, &c);
			if (Board[y][x] != c)
				Cover(x-1, y-1, c, Board[y][x]);
		}
		else if (op == 'S') {
			string str;
			cin >> str;
			cout << str << endl;
			for (int y=0; y<N; ++y) {
				for (int x=0; x<M; ++x)
					printf("%c", Board[y][x]);
				puts("");
			}
		}
		else {
			char str[20];
			gets(str);
		}
	}

	return 0;
}



#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int s, call[10][7] = 
{{1,2,3,4,5,7}, {1, 2}, {5, 1, 6, 4, 7}, {1,2,5,6,7}, {1,2,3,6}, {2,3,5,6,7}, {2,3,4,5,6,7}, {1,2,5}, {1,2,3,4,5,6,7}, {1,2,3,5,6,7}};
string Num;
char board[100][200];

void Solve (int toMake, int d) {

	int x = d*(s+3);

	if (toMake == 1) 
		for (int i=1; i<=s; ++i) board[i][x+s+1] = '|';
	else if (toMake == 2)
		for (int i=s+2; i<=2*s+1; ++i) board[i][x+s+1] = '|';
	else if (toMake == 3)
		for (int i=1; i<=s; ++i) board[i][x] = '|';
	else if (toMake == 4)
		for (int i=s+2; i<=2*s+1; ++i) board[i][x] = '|';
	else if (toMake == 5)
		for (int j=1; j<=s; ++j) board[0][x+j] = '-';
	else if (toMake == 6)
		for (int j=1; j<=s; ++j) board[1+s][x+j] = '-';
	else if (toMake == 7)
		for (int j=1; j<=s; ++j) board[2*s+2][x+j] = '-';
}




int main() {
	int n=0;
	while (1) {
		memset(board, 0, sizeof(board));
		cin >> s >> Num;
		if (s == 0) break;

		for (int i=0; i<=Num.size(); ++i)
			for (int j=0; j<7; ++j)
				Solve (call[Num[i] - '0'][j], i);

		if (n>0) puts("");
		for (int i=0; i<2*s+3; ++i) {
			for (int j=0; j<Num.size()*(s+3)-1; ++j)
				printf("%c", board[i][j] == '\0' ? ' ' : board[i][j]);
			puts("");
		}
		++n;
		
	}
	return 0;
}



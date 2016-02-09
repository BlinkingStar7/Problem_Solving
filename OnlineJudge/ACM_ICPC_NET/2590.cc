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


int Paper[7], ans, Board[7][7];

void Cover(int num, int a) {
	for (int i=0; i<6; ++i) {
		for (int j=0; j<6; ++j) {
			if (num == 0) break;
			if (Board[i][j]==0 && (i+a)<=6 && (j+a)<=6) {
				--Paper[a];
				--num;
				for (int y=0; y<a; ++y)
					for (int x=0; x<a; ++x)
						Board[i+y][j+x] = 1;
			}
		}
	}
}

int main () {
	for (int i=1; i<=6; ++i)
		scanf("%d", Paper+i);

	ans += Paper[6];
	int cur = 5;
	while (1) {
		if (cur == 0) break;
		if (Paper[cur] == 0) {
			--cur;
			continue;
		}
		memset(Board, 0, sizeof(Board));
		++ans;

		int inOneBoard = (6/cur)*(6/cur);
		if (Paper[cur] >= inOneBoard) {
			Cover(inOneBoard, cur);
		}
		else { 
			Cover(Paper[cur], cur);
		}

		for (int small = 6-cur; small>=1; --small)
			Cover(Paper[small], small);
	}

	cout << ans << endl;

	return 0;
}


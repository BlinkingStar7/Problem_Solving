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

bool board[101][101];
int main () {
	for (int i=0; i<4; ++i) {
		int x, xx, y, yy;
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		for (int xxx=x; xxx<xx; ++xxx){
			for (int yyy=y; yyy<yy; ++yyy) {
				board[yyy][xxx] = true;
			}
		}
	}
	int num =0;
	for (int i =1; i<=100; ++i)
		for (int j=1; j<=100; ++j)
			if (board[i][j])
				++num;
	cout << num << endl;

	return 0;
}


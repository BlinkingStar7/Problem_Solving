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

int testNum, Board[41][41], N, M, n, k;
pair<int, int> W[21], A[21];
bool flag;

void connect(int x, int y, int ax, int ay) {
	if (flag) return;
	if (Board[x][y]) return;

	Board[x][y] = 1;
	
	if (x == ax && y == ay) {
		flag = true;
		return;
	}
	if (x>ax) connect(x-1, y, ax, ay);
	if (y>ay) connect(x, y-1, ax, ay);
	if (x<ax) connect(x+1, y, ax, ay);
}

int main () {
	cin >> testNum;

	while (testNum--) {
		memset(Board, 0, sizeof(Board));
		cin >> N >> M >> n >> k;

		for (int i=0; i<n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			W[i] = make_pair(x, y);
		}
		for (int i=0; i<n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			A[i] = make_pair(x, y);
		}
		sort(W, W+n);
		sort(A, A+n);

		for (int i=0; i<n; ++i) {
			flag = false;
			connect(W[i].first, W[i].second, A[i].first, A[i].second);
			if (!flag) {
				break;
			}
		}
		if (flag) printf("1\n");
		else printf("-1\n");
	}


	return 0;
}


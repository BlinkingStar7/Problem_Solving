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

int N, Board[11][11];
bool D[2][21];
int cnt = 0;

int Solve (int y, int x, int r) {
	++cnt;
	if (x >= N) return Solve (y+1, (y+1)%2==r ? 0 : 1, r);
	if (y >= N) return 0;
	if (Board[y][x] == 0) return Solve(y, x+2, r);

	int d1 = y+x, d2 = y-x+N-1, ret = Solve(y, x+2, r);
	if (!D[0][d1] || !D[1][d2]) return ret;
	else {
		D[0][d1] = D[1][d2] = false;
		ret = max (ret, 1+ Solve(y, x+2, r));
		D[0][d1] = D[1][d2] = true;
	}
	return ret;

}




int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j) {
			scanf("%d", &Board[i][j]);
		}

	memset (D, true, sizeof(D));
	cout << Solve (0, 0, 0) + Solve(0, 1, 1) << endl;
	printf("%d\n", cnt);
	return 0;
}

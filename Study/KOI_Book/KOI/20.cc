#include <iostream>
#include <cstring>
using namespace std;

int H, W, memo[11][11];

int Solve(int y, int x) {

	if ((W*y > H*x) || y > H || x > W) return 0;
	if (y == H && x == W) return 1;
	int &ret = memo[y][x];
	if (ret != -1) return ret;

	return ret = Solve(y+1, x) + Solve (y, x+1);
}	

int main() {
	cin >> H >> W;
	memset(memo, -1, sizeof(memo));
	cout << Solve(0, 0) << endl;

	return 0;
}

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

int Map[26][26], N;
const int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
int dfs (int y, int x) {
	Map[y][x] = 0;
	int ret = 1;
	for (int i=0; i<4; ++i) {
		int ny = y+dy[i], nx = x+dx[i];
		if (ny>=0&&nx>=0&&nx<N&&ny<N&& Map[ny][nx] == 1)
			ret += dfs(ny, nx);
	}
	return ret;
}

int main () {
	cin >> N;
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j)
			scanf("%1d", &Map[i][j]);
	}

	vector<int> ans; 

	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			if (Map[i][j] == 1) {
				int num = dfs(i, j);
				ans.push_back(num);
			}
		}
	}

	cout << ans.size() << endl;
	sort (ans.begin(), ans.end());
	for (int i=0; i<ans.size(); ++i)
		cout << ans[i] << endl;

	return 0;
}


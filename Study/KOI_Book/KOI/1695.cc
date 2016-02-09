#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int	M, Board[25][25];

int dfs (int y, int x) {
	if (Board[y][x] == 0 || y<0 || x<0 || y>=M || x>=M) return 0;
	Board[y][x] = 0;
	return 1 + dfs(y+1, x) + dfs (y-1, x) + dfs (y, x+1) + dfs(y, x-1);
}

int main() {
	cin >> M ;

	for (int i=0; i<M; ++i)
		for (int j=0; j<M; ++j)
			scanf("%1d", &Board[i][j]);

	vector<int> l;
	for (int i=0; i<M; ++i)
		for (int j=0; j<M; ++j)
			if (Board[i][j])
				l.push_back(dfs (i, j));
	sort (l.begin(), l.end());
	cout << l.size() << endl;
	for (int i=0; i<l.size(); ++i)
		cout << l[i] << endl;
	return 0;
}

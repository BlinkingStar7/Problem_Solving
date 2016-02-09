#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	M, N, K, Board[101][101];

int dfs (int y, int x) {
	if (Board[y][x] == 1 || y<0 || x<0 || y>=M || x>=N) return 0;
	Board[y][x] = 1;
	return 1 + dfs(y+1, x) + dfs (y-1, x) + dfs (y, x+1) + dfs(y, x-1);
}

int main() {
	cin >> M >> N >> K;

	for (int i=0; i<K; ++i) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y=y1; y<y2; ++y)
			for (int x=x1; x<x2; ++x)
				Board[y][x] = 1;
	}
	vector<int> l;
	for (int i=0; i<M; ++i)
		for (int j=0; j<N; ++j)
			if (!Board[i][j])
				l.push_back(dfs (i, j));
	sort (l.begin(), l.end());
	cout << l.size() << endl;
	for (int i=0; i<l.size(); ++i)
		cout << l[i] << ' ';
	return 0;
}

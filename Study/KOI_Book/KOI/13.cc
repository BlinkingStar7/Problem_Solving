#include <iostream>
#include <vector>
using namespace std;
int N, M, color[201]; vector<vector<int> > G(200);

int Solve(int f) {
	for (int i=0; i<G[f].size(); ++i) {
		if (color[G[f][i]] == 0) {
			color[G[f][i]] = color[f] == 1 ? 2 : 1;
			Solve(G[f][i]);
		}
		else if (color[G[f][i]] == color[f])
			return -1;
	}
	return 0;
}

int main() {
	cin >> N >> M;

	for (int i=0; i<M; ++i) {
		int f, t;
		cin >> f >> t;
		G[f].push_back(t);
		G[t].push_back(f);
	}
	color[0] = 1;
	cout << Solve(0) << endl;
	return 0;
}



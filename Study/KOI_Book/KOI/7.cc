#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct ELE { int to, cost; } E;
int N, M; vector<vector<E> > graph (10 + 1);
#define MAX 987654321

int Solve(int f, int visited) {
	if (f == N) return 0;

	int ret = MAX;
	for (int i=0; i<graph[f].size(); ++i) {
		E next = graph[f][i];
		int to = next.to, cost = next.cost;
		if ((visited & 1 << to) == 0)
			ret = min (ret, cost + Solve(to, visited & 1 << to));
	}
	return ret;
}

int main() {
	cin >> N >> M;
	for (int i=0; i<M; ++i) {
		int f, t, c;
		cin >> f >> t >> c;
		graph[f].push_back((E) {t, c});
	}

	cout << Solve (1, 0) << endl;
	return 0;
}


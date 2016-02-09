#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct Element {int to, cost;} E;
typedef struct Node {int to, cost, visit;} Node;
vector <vector<E> > G (10+1);
queue <Node> Q;
int N, M, Min = 987654321;

int main() {
	cin >> N >> M;

	for (int i=0; i<M; ++i) {
		int f, t, c;
		cin >> f >> t >> c;
		G[f].push_back((E) {t, c});
		G[t].push_back((E) {f, c});
	}
	
	Q.push((Node) {1, 0, 1});
	while (!Q.empty()) {
		Node cur = Q.front(); Q.pop();
		if (cur.to == N) {
			if (cur.cost < Min)
				Min = cur.cost;
			continue;
		}
		for (int i=0; i<G[cur.to].size(); ++i) { 
			if ((cur.visit & (1 << G[cur.to][i].to)) == 0)
				Q.push((Node) {G[cur.to][i].to, G[cur.to][i].cost + cur.cost, cur.visit & 1 << G[cur.to][i].to});
		}
	}

	if (Min == 987654321) cout << -1 << endl;
	else cout << Min << endl;

	return 0;
}

	


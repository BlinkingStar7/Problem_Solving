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

int N, M, G[10][10];

void getEulerCircuit(int here, vector<int>& circuit) {
	for (int there=0; there<N; ++there)
		while (G[here][there] > 0) {
			G[here][there]--;
			G[there][here]--;
			getEulerCircuit(there, circuit);
		}
	circuit.push_back(here);
}
int main () {
	cin >> N >> M;
	for (int i=0; i<M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		G[a][b]++;
		G[b][a]++;
	}
	vector<int> circuit;
	getEulerCircuit(0, circuit);
	for (int i=0; i<circuit.size(); ++i)
		printf("%d ", circuit[i]);
	puts("");


	return 0;
}


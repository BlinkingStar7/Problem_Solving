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

int testNum, N;

int Find (int set, int disc) {
	return (set & 3<<(disc*2)) >> (disc*2);
}

int Modify (int set, int disc, int to) {
	return (set&~(3<<(disc*2)))| (to<<(disc*2));
}

vector<int> GetAdj(int set) {
	vector<int> ret, poll[4];
	
	for (int i=1; i<=N; ++i) {
		int p = Find(set, i);
		poll[p].push_back(i);
	}

	for (int i=0; i<4; ++i) {
		for (int j=0; j<4; ++j) {
			if (i == j) continue;
			if (poll[i].size() == 0) continue;
			if (poll[j].size() == 0 || poll[i][0] < poll[j][0])
				ret.push_back(Modify(set, poll[i][0], j));
		}
	}
	return ret;
}

		
int BFS (int start) {
	int end = (1<<((N+1)*2))-4;
	if (end == start) return 0;

	queue<int> q;
	map<int, int> m;
	q.push(start); q.push(end);
	m[start] = 1;
	m[end] = -1;

	while (!q.empty()) {
		int here = q.front(); q.pop();
		int cost = m[here];

		vector<int> adj = GetAdj(here);
		for (int i=0; i<adj.size(); ++i) {
			if (m.count(adj[i]) == 0) {
				m[adj[i]] = (cost>0) ? cost+1 : cost-1;
				q.push(adj[i]);
			}
			else if (m[adj[i]] * cost < 0)
				return abs(m[adj[i]]) + abs(cost) -1;
		}
	}

	return -1;
}

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N;

		int set = 0;
		for (int i=0; i<4; ++i) {
			int num;
			scanf("%d", &num);
			for (int ii=0; ii<num; ++ii) {
				int disc;
				scanf("%d", &disc);
				set = Modify(set, disc, i);
			}
		}


		cout << BFS(set) << endl;
	}


	return 0;
}


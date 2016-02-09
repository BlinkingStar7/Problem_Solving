#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int N, M, Ans[100001], Pos[100001];
vector<pair<int, int> > Robot[100001];
bool Visited[100001];

void dfs (int here, vector<int> &topological) {
	Visited[here] = true;
	for (int i=0; i<Robot[here].size(); ++i) 
		if (!Visited[Robot[here][i].first])
			dfs (Robot[here][i].first, topological);
	topological.push_back(here);
}

void dfsAll(vector<int> &topological) {
	for (int i=1; i<=N; ++i) {
		if (!Visited[i])
			dfs (i, topological);
	}
}

void Solve (vector<int>& topological, int n, int num) {
	int here = topological[n];
	bool flag = true;
	for (int i=0; i<Robot[here].size(); ++i) {
		flag = false;
		Solve (topological, Pos[Robot[here][i].first], num*Robot[here][i].second);
	}
	if (flag)
		Ans[here] += num;
}
int main() {
	cin >> N >> M;

	for (int i=0; i<M; ++i) {
		int a, b, x;
		scanf("%d %d %d", &a, &b, &x);
		Robot[a].push_back(make_pair(b, x));
	}

	vector<int> topological;
	dfsAll(topological);
	reverse(topological.begin(), topological.end());
	for (int i=0; i<topological.size(); ++i)
		Pos[topological[i]] = i;


	Solve (topological, 0, 1);
	for (int i=1; i<=N; ++i)
		if (Ans[i])
			printf("%d %d\n", i, Ans[i]);

	return 0;
}



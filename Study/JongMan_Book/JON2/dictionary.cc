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

int testNum, N, G[27][27];
string Word[1001];
bool Visited[27];

void makeEdge () {
	for (int j=1; j<N; ++j) {
		int i=j-1, len = min(Word[i].size(), Word[j].size());
		for (int k=0; k<len; ++k)
			if (Word[i][k] != Word[j][k]) {
				G[Word[i][k]-'a'][Word[j][k]-'a'] = 1;
				break;
			}
	}
}

void dfs (int n, vector<int>& topological) {
	Visited[n] = true;
	for (int next=0; next<26; ++next)
		if (!Visited[next] && G[n][next])
			dfs (next, topological);
	topological.push_back (n);
}

void dfsAll(vector<int>& topological) {
	for (int i=0; i<26; ++i)
		if (!Visited[i])
			dfs(i, topological);
}

int main () {
	cin >> testNum;

	while (testNum--) {
		memset(Visited, false, sizeof(Visited));
		memset(G, 0, sizeof(G));

		cin >> N;
		for (int i=0; i<N; ++i)
			cin >> Word[i];

		makeEdge ();
		
		vector<int> topological;

		dfsAll(topological);
		reverse(topological.begin(), topological.end());

		memset(Visited, false, sizeof(Visited));
		bool flag = true;
		for (int i=0; i<26; ++i) {
			int cur = topological[i];
			Visited[cur] = true;
			for (int j=0; j<26; ++j)
				if (G[cur][j] && Visited[j]) {
					flag = false;
					break;
				}
			if (!flag) break;
		}
		
		if (!flag) 
			printf("INVALID HYPOTHESIS\n");
		else {
			for (int i=0; i<topological.size(); ++i)
				printf("%c", 'a' + topological[i]);
			puts("");
		}
	}


	return 0;
}


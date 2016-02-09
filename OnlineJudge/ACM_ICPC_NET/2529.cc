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

int Visited[11], adj[11][11], cnt, Ans[11], K;
void dfs(int here) {
	Visited[here] = 1;
	for (int i=0; i<=K; ++i) {
		if (!Visited[i] && adj[here][i])
			dfs(i);
	}
	Ans[here] = cnt++;
}

int main () {
	cin >> K;
	for (int i=0; i<K; ++i) {
		char c;
		scanf(" %c", &c);
		if (c == '>') 
			adj[i][i+1] = 1;
		else
			adj[i+1][i] = 1;
	}

	cnt = 9-K;
	for (int i=K; i>=0; --i)
		if (!Visited[i])
			dfs(i);
	for (int i=0; i<=K; ++i)
		printf("%d", Ans[i]);

	memset(Visited, 0, sizeof(Visited));
	cnt = 0;
	puts("");
	for (int i=0; i<=K; ++i)
		if (!Visited[i])
			dfs(i);
	for (int i=0; i<=K; ++i)
		printf("%d", Ans[i]);

	return 0;
}


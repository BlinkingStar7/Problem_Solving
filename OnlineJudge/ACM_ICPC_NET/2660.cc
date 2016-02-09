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

int N, adj[51][51];

int main () {
	cin >> N;
	while (1) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == -1) break;
		adj[a][b] = adj[b][a] = 1;
	}

	for (int i=1; i<=N; ++i) for (int j=1; j<=N; ++j)
		if (i == j) adj[i][j] = 0;
		else if (adj[i][j] == 0) adj[i][j] = 9999;

	for (int k=1; k<=N; ++k)
		for (int i=1; i<=N; ++i) {
			for (int j=1; j<=N; ++j) {
				adj[i][j] = min (adj[i][j], adj[i][k] + adj[k][j]);
			}
		}

	vector<int> ans;
	int Min = 9999;
	for (int i=1; i<=N; ++i) {
		int num = 0;
		for (int j=1; j<=N; ++j)
			num = max(num, adj[i][j]);
		if (num <= Min) {
			if (num < Min) ans.clear();
			Min = num;
			ans.push_back(i);
		}
	}
	cout << Min << " " << ans.size() << endl;
	for (int i=0; i<ans.size(); ++i)
		printf("%d ", ans[i]); 

		

				

	return 0;
}


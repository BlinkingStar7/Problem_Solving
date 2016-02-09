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

int N, K, V[1001], Path[1001];
vector<int> adj[1001];

int main () {
	memset(Path, -1, sizeof(Path));
	cin >> N >> K;
	for (int i=0; i<N; ++i) {
		int x=0, d;
		for (int j=K-1; j>=0; --j) {
			scanf("%1d", &d);
			x += (d << j);
		}
		V[i] = x;
	}

	for (int i=0; i<N; ++i) {
		for (int j=i+1; j<N; ++j) {
			if (__builtin_popcount(V[i]^V[j]) == 1) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	int A, B;
	cin >> A >> B;
	--A, --B;

	queue<int> q;
	q.push(A);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i=0; i<adj[cur].size(); ++i) {
			int next = adj[cur][i];
			if (Path[next] == -1) {
				Path[next] = cur;
				q.push(next);
			}
		}
	}

	if (Path[B] == -1) {
		cout << -1 << endl;
	}
	else {
		vector<int> ans;
		int cur = B;
		while (cur != A) {
			ans.push_back(cur+1);
			cur = Path[cur];
		}
		ans.push_back(cur+1);
		for (int i=ans.size()-1; i>=0; --i)
			printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}


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

int N, adj[101][101];
int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j)
			scanf("%d", &adj[i][j]);

	vector<bool> tested(N, false);
	vector<vector<int> > ans;
	bool flag = true;
	for (int i=0; i<N; ++i) {
		if (tested[i]) continue;
		vector<int> cur;
		for (int j=0; j<N; ++j) {
			if (adj[i][j] == 0) {
				cur.push_back(j+1);
				if (j == i || tested[j]) continue;
				for (int k=0; k<N; ++k) {
					if (adj[i][k] != adj[j][k]) {
						flag = false;
						break;
					}
				}
				tested[j] = true;
			}
		}
		if (cur.size() == 1)
			flag = false;
		if (!flag) break;
		tested[i] = true;
		ans.push_back(cur);
	}

	if (!flag) {
		cout << 0 << endl;
	}
	else {
		cout << ans.size() << endl;
		for (int i=0; i<ans.size(); ++i) {
			for (int j=0; j<ans[i].size(); ++j)
				printf("%d ", ans[i][j]);
			puts("");
		}
	}



	return 0;
}


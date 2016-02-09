#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) ;
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int to[50001], size[50001], N;
bool visited[50001];

int dfs(int cur, vi& selected) {
	visited[cur] = true;
	selected.push_back(cur);
	int next = to[cur];

	if (visited[next]) {
		auto it = vi::reverse_iterator(find(selected.begin(), selected.end(), next));
		int s = it - selected.rbegin();
		s = s == 0 ? size[next] : s;
		for (auto trv = selected.rbegin(); trv != it; ++trv)
			size[*trv] = s;
		for (auto trv = it; trv != selected.rend(); ++trv)
			size[*trv] = ++s;
		return s;
	}

	return dfs(next, selected);
}

int main () {
	int t;
	scanf("%d", &t);
	for (int tt=1; tt<=t; ++tt) {
		scanf("%d", &N);
		for (int i=0; i<N; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			to[a] = b;
		}

		memset(size, 0, sizeof(size));
		memset(visited, false, sizeof(visited));
		int ans=-1, mmax = 0;
		for (int i=1; i<=N; ++i)
			if (!visited[i]) {
				int cand = dfs(i, vi());
				if (cand > mmax) {
					ans = i;
					mmax = cand;
				}
			}
		printf("Case %d: %d\n", tt, ans);
	}

	return 0;
}



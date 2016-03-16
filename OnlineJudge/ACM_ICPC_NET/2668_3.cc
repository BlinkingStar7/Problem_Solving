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

int n, f[102], counter, visited[102];

bool dfs (int cur, int start) {
	if (cur == start) return true;
	if (visited[cur] == counter) return false;
	visited[cur] = counter;
	return dfs(f[cur], start);
}

vi ans;
int main () {
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", f+i);
	
	for (int i=1; i<=n; ++i) {
		++counter;
		if (dfs(f[i], i)) ans.push_back(i);
	}

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i=0; i<ans.size(); ++i)
		printf("%d\n", ans[i]);

	return 0;
}



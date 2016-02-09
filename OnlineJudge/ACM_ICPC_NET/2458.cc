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

bool visited[501], smaller[501][501], bigger[501][501];
int N, M, size[501];

int dfs(int here, bool (&adj)[501][501]) {
	visited[here] = true;
	int ret = 0;

	for (int there=1; there<=N; ++there) {
		if (adj[here][there]) {
			if (!visited[there]) ret += 1 + dfs(there, adj);
			else if (size[there] != -1) ret += size[there];
		}
	}

	size[here] += ret;
	return ret;
}

int main () {
	scanf("%d%d", &N, &M);

	for (int i=0; i<M; ++i) {
		int a, b;
		scanf("%d%d", &a,&b);
		smaller[a][b] = true;
		bigger[b][a] = true;
	}

	memset(size, -1, sizeof(size));
	for (int i=1; i<=N; ++i)
		if (!visited[i]) dfs(i, smaller);
	memset(visited, false, sizeof(visited));
	for (int i=1; i<=N; ++i)
		if (!visited[i]) dfs(i, bigger);

	int ans = 0;
	for (int i=1; i<=N; ++i)
		if (size[i] == N - 1) ++ans;

	printf("%d\n", ans);

	return 0;
}



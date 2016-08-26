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
typedef long long ll;
typedef unsigned long long ull;

int N, p[101][2], g[101];
vi x[1001], y[1001];
void dfs(int cur, int cnt) {
	g[cur] = cnt;
	for (int i=0; i<x[p[cur][0]].size(); ++i) {
		int next = x[p[cur][0]][i];
		if (!g[next]) dfs(next, cnt);
	}
	for (int i=0; i<y[p[cur][1]].size(); ++i) {
		int next = y[p[cur][1]][i];
		if (!g[next]) dfs(next, cnt);
	}
}

int main () {
	scanf("%d", &N);
	for (int i=0; i<N; ++i) {
		scanf("%d%d", &p[i][0], &p[i][1]);
		x[p[i][0]].push_back(i);
		y[p[i][1]].push_back(i);
	}

	int cnt = 1;
	for (int i=0; i<N; ++i)
		if (!g[i]) dfs(i, cnt++);

	printf("%d\n", cnt-2);
	return 0;
}



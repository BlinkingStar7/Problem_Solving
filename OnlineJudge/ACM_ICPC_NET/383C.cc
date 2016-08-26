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

const int MAX = 200005;
int cnt, N, M, A[MAX], P[MAX], End[MAX], Sign[MAX], fw[MAX];
vi adj[MAX];

void dfs (int cur) {
	P[cur] = ++cnt;
	for (int i=0; i<adj[cur].size(); ++i) {
		int next = adj[cur][i];
		dfs (next);
	}
}
	
void dfs (int cur, int end, int s) {
	Sign[P[cur]] = s;
	End[P[cur]] = P[end];

	for (int i=0; i<adj[cur].size(); ++i) {
		int next = adj[cur][i];
		int e = i == adj[cur].size()-1 ? end : adj[cur][i+1];
		dfs (next, e, -s);
	}
}

void update (int p, int v) {
	for (; p<=N; p += p & -p) fw[p] += v;
}

int query (int p) {
	int ret = 0, ori = p;
	for (; p; p -= p & -p) ret += fw[p];
	return Sign[ori]*ret;
}

int main () {
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; ++i)
		scanf("%d", A+i);

	for (int i=0; i<N-1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}

	dfs(1);
	P[N+1] = N+1;
	dfs(1, N+1, 1);


	for (int i=0; i<M; ++i) {
		int cmd, a, b;
		scanf("%d%d", &cmd, &a);

		if (cmd == 1) {
			scanf("%d", &b);
			update(P[a], Sign[P[a]] * b);
			update(End[P[a]], Sign[P[a]] * -b);
		}
		else {
			printf("%d\n", A[a] + query(P[a]));
		}
	}
	
	return 0;
}



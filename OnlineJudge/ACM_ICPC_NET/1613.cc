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

int n, k, s, in[401], parent[401], v[401];
vi adj[401];

int p(int a) {
	return parent[a] = parent[a] == a ? a : p(parent[a]);
}

void merge(int a, int b) {
	a = p(a), b = p(b);
	parent[b] = a;
}

int main () {
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; ++i) parent[i] = i;
	for (int i=0; i<k; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		adj[a].push_back(b);
		++in[b];
		merge(a, b);
	}

	queue<int> q;
	for (int i=0; i<n; ++i)
		if (in[i] == 0) {
			q.push(i);
			v[i] = 1;
		}

	while(!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i=0; i<adj[cur].size(); ++i) {
			int next = adj[cur][i];
			if (--in[next] == 0) {
				q.push(next);
				v[next] = v[cur]+1;
			}
		}
	}
	

	scanf("%d", &s);
	for (int i=0; i<s; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		if (p(a) != p(b) || v[a] == v[b]) printf("0\n");
		else printf("%d\n", v[a] < v[b] ? -1 : 1);
	}
	return 0;
}



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

int n, k, p[100001];
bool v[100001];
map<int, int> m;
vi adj[100001];

int main () {
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; ++i) {
		int num = 0;
		for (int j=0; j<k; ++j) {
			num <<= 1;
			int t; scanf("%1d", &t);
			num |= t;
		}
					
		m[num] = i+1;
		for (int jj=0; jj<k; ++jj) {
			int cand = num ^ (1<<jj);
			if (m.find(cand) != m.end()) {
				int next = m[cand];
				adj[i+1].push_back(next);
				adj[next].push_back(i+1);
			}
		}
	}

	queue<int> q; q.push(1);
	v[1] = true; p[1] = -1;
	

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i=0; i<adj[cur].size(); ++i) {
			int next = adj[cur][i];
			if (!v[next]) {
				p[next] = cur;
				v[next] = true;
				q.push(next);
			}
		}
	}

	int mm; scanf("%d", &mm);
	for (int i=0; i<mm; ++i) {
		int to; scanf("%d", &to);
		if (v[to]) {
			vi ans;
			int cur = to;
			while (cur != -1) {
				ans.push_back(cur);
				cur = p[cur];
			}
			for (int i=ans.size()-1; i>=0; --i)
				printf("%d%c", ans[i], i ? ' ' : '\n');
		}
		else 
			printf("-1\n");
	}

	return 0;
}



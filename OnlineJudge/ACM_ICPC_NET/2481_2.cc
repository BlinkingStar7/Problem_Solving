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

#define MAX_N 100001
int n, k, p[MAX_N];
bool v[MAX_N];
pii code[MAX_N];

int main () {
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; ++i) {
		int num=0;
		for (int j=0; j<k; ++j) {
			int t;
			scanf("%1d", &t);
			num <<= 1;
			num |= t;
		}
		code[i] = make_pair(num, i+1);
	}
	sort(code+1, code+n);

	queue<pii> q; q.push(code[0]);
	v[1] = true; p[1] = -1;
	
	while (!q.empty()) {
		int cur = q.front().first, ind = q.front().second; q.pop();
		for (int i=0; i<k; ++i) {
			int cand = cur ^ (1<<i);
			int pos = lower_bound(code+1, code+n, make_pair(cand, 0)) - code;
			if (pos == n || code[pos].first != cand) continue;

			int next = code[pos].first, nind = code[pos].second;
			if (next == cand && !v[nind]) {
				v[nind] = true;
				p[nind] = ind;
				q.push(code[pos]);
			}
		}
	}

	int m; scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		int t; scanf("%d", &t);
		if (v[t]) {
			vi ans;
			int cur = t;
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



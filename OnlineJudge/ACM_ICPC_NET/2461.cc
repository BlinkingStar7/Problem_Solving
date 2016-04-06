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

int n, m, b[1001][1001], ans = 1<<30;

struct comp {
	bool operator() (const int &aa, const int &bb) const {
		return b[aa/1000][aa%1000] > b[bb/1000][bb%1000];
	}
};

int main () {
	scanf("%d%d", &n, &m);

	int mmax = -INF;
	priority_queue<int, vector<int>, comp> pq;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j)
			scanf("%d", &b[i][j]);
		sort(b[i], &b[i][0]+m);
		pq.push(1000*i);
		mmax = max (mmax, b[i][0]);
	}
	
	while(1) {
		int cur = pq.top(); pq.pop();
		int g = cur/1000, ind = cur%1000;

		ans = min (ans, mmax - b[g][ind]);
		if (ind == m-1) break;

		if (b[g][ind+1] > mmax)
			mmax = b[g][ind+1];

		pq.push(cur+1);
	}

	printf("%d\n", ans);
	return 0;
}



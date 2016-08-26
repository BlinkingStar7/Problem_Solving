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

int n, t, a[100001], d[2] = {1, -1}, v[100001];
long long solve(int k) {
	memset(v, 0, sizeof(v));
	priority_queue<pii, vpii, greater<pii> > pq;
	int b[100001];

	memcpy(b, a, n*sizeof(int));

	for (int i=0; i<n; ++i)
		pq.push(make_pair(a[i], i));

	long long ret = 0;
	for (int i=0; i<n; ) {
		int cur = pq.top().second, val = pq.top().first;
		pq.pop();
		if (v[cur]) continue;
		else v[cur] = val;
		++i;

		for (int j=0; j<2; ++j) {
			int adj = cur + d[j];
			if (adj>=n || adj<0 || v[adj] || b[adj] <= val + k) continue;
			ret += b[adj] - (val + k);
			b[adj] = val+k;
			pq.push(make_pair(val+k, adj));
		}
	}

	return ret;
}

int main () {
	scanf("%d%d", &n, &t);
	for (int i=0; i<n; ++i)
		scanf("%d", a+i);

	int lo=0, hi=1e9;
	while (lo < hi) {
		int mid = lo + (hi-lo)/2;
		if (solve(mid)<=t) hi = mid;
		else lo = mid+1;
	}

	solve(lo);

	for (int i=0; i<n; ++i)
		printf("%d ", v[i]);
	
	return 0;
}



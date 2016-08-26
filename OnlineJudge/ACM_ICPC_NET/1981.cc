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

int n, c[201], ans = INF, dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0}, p[101*101], r[101*101];
bool v[101*101];
pii s[101*101];

int f(int a) {
	return p[a] = p[a] == a ? a : f(p[a]);
}

void m(int a, int b) {
	a = f(a), b = f(b);
	if (a == b) return;
	if (r[a] > r[b]) swap(a, b);
	p[a] = b;
	if (r[a] == r[b]) r[b]++;
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
		int v;
		scanf("%d", &v);
		c[v]++;
		s[i*n+j] = make_pair(v, i*n+j);
	}

	sort(s, s+n*n);
	
	int ttt = 0;
	for (int th=0; th<=200; ++th) if (c[th]) {
		for (int i=0; i<n*n; ++i) {
			p[i] = i;
			r[i] = 1;
		}
		memset(v, 0, sizeof(v));

		while (s[ttt++].first < th) ;
		int pos = ttt;
		while (pos<n*n) {
			int cur = s[pos].second;
			v[cur] = true;
			for (int d=0; d<4; ++d) {
				int ny = cur/n + dy[d], nx = cur%n + dx[d];
				int next = ny*n+nx;
				if (ny>=0 && ny<n*n && nx>=0 && nx<n*n && v[next]) {
					m(cur, next);
				}
			}
			if (f(0) == f(n*n-1))  {
				ans = min(ans, s[pos].first - th);
				break;
			}
			++pos;
		}

	}

	printf("%d\n", ans);
	return 0;
}



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

int n, f[102],in [102];
int main () {
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		int t; scanf("%d", f+i);
		in[f[i]]++;
	}

	queue<int> q;
	for (int i=1; i<=n; ++i) if (!in[i]) {
		q.push(i);
	}

	int ans = n;
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		--ans;
		--in[f[cur]];
		if (in[f[cur]] == 0) q.push(f[cur]);
	}

	printf("%d\n", ans);
	for (int i=1; i<=n; ++i) if (in[i])
		printf("%d\n", i);

	return 0;
}



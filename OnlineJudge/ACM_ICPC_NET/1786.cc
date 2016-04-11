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

char H[1000001], N[1000001];
int n, m, p[1000001];
vi ans;
int main () {
	gets(H); gets(N);
	n = strlen(H);
	m = strlen(N);

	int c = 0;
	for (int i=1; i<m; ++i) {
		while (c > 0 && N[i] != N[c]) c = p[c-1];
		if (N[i] == N[c])
			p[i] = ++c;
	}

	c = 0;
	for (int i=0; i<n; ++i) {
		while (c > 0 && H[i] != N[c]) c = p[c-1];
		if (H[i] == N[c]) {
			if (++c == m) {
				ans.push_back(i-m+2);
				c = p[c-1];
			}
		}
	}

	printf("%d\n", ans.size());
	for (int i=0; i<ans.size(); ++i)
		printf("%d ", ans[i]);
	return 0;
}



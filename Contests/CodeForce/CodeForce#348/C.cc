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

int n, m, q, t[10001][4], ans[101][101];
int main () {
	scanf("%d%d%d", &n,&m,&q);
	for (int i=0; i<q; ++i) {
		scanf("%d", &t[i][0]);
		if (t[i][0] == 1 || t[i][0] == 2) {
			scanf("%d", &t[i][1]);
		}
		else {
			scanf("%d%d%d", &t[i][1], &t[i][2], &t[i][3]);
		}
		--t[i][1];
		--t[i][2];
	}

	for (int i=q-1; i>=0; --i) {
		if (t[i][0] == 3)
			ans[t[i][1]][t[i][2]] = t[i][3];
		else if (t[i][0] == 1) {
			int rr = t[i][1];
			int temp = ans[rr][m-1];
			for (int j=m-1; j>=1; --j)
				ans[rr][j] = ans[rr][j-1];
			ans[rr][0] = temp;
		}
		else {
			int cc = t[i][1];
			int temp = ans[n-1][cc];
			for (int j=n-1; j>=1; --j)
				ans[j][cc] = ans[j-1][cc];
			ans[0][cc] = temp;
		}
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			printf("%d%c", ans[i][j], j==m-1?'\n':' ');

	return  0;
}



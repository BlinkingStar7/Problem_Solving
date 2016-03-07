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

int n, m, t, k, X[101], Y[101];
pii dia[101];

int main () {
	scanf("%d%d%d%d", &n, &m, &t, &k);
	for (int i=0; i<t; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		X[i] = x, Y[i] = y, dia[i] = make_pair(x, y); 
	}
	sort (X, X+t); sort (Y, Y+t);
	int xnum = unique(X, X+t) - X, ynum = unique(Y, Y+t) - Y;

	int best=-1, ax, ay;
	for (int i=0; i<xnum; ++i) 
		for (int j=0; j<ynum; ++j) {
			int cnt = 0;
			for (int p=0; p<t; ++p) {
				if (dia[p].first >= X[i] && dia[p].first <= X[i]+k &&
					dia[p].second>= Y[j] && dia[p].second<= Y[j]+k) ++ cnt;
			}
			if (cnt > best) {
				ax = min(X[i], n-k), ay = min(Y[j]+k, m);
				best = cnt;
			}

		}
	printf("%d %d\n%d\n",ax, ay, best);

	return 0;
}



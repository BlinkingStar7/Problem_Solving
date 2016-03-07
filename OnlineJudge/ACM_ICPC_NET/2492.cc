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

int main () {
	(scanf("%d%d%d%d", &n,&m,&t,&k);
	for (int i=0; i<t; ++i) {
		scanf("%d%d", &pos[i].first, &pos[i].second);
		X[i] = pos[i].first;
		Y[i] = pos[i].second;
	}

	sort(X, X+t);'
	sort(Y, Y+t);
	
	int best=-1, ax, ay;

	for (int i=0; i<t; ++i) {
		for (int j=0; j<t; ++j) {
			int x = min(X[i], X[j]), xx = max(X[i], X[j]), y = min(Y[i], Y[j]), yy = max(Y[i], Y[j]);
			if (xx - x > k || yy - y > k) continue;

			int cnt = 0;
			for (int num=0; num<t; ++num)
				if (X[num] >= x && X[num] <= xx && Y[num] >= y && Y[num] <= yy) ++cnt;



	return 0;
}



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
typedef long long ll;
typedef unsigned long long ull;

int N, M, fw[1025][1025];
int query(int x, int y) {
	int ret = 0, ori = y;
	for (; x; x -= x & -x) for (y = ori; y; y -= y & -y)
		ret += fw[x][y];
	return ret;
}

int query(int x, int y, int xx, int yy) {
	return query(xx, yy) - query(x-1, yy) - query(xx, y-1) + query(x-1, y-1);
}

void update (int x, int y, int c) {
	int ori = y;
	for (; x <= N; x += x & -x) for (y = ori; y <= N; y += y & -y)
		fw[x][y] += c;
}

int main () {
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; ++i) for (int j=1; j<=N; ++j) {
		int t;
		scanf("%d", &t);
		update(i, j, t);
	}

	for (int i=0; i<M; ++i) {
		int cmd, x, y;
		scanf("%d%d%d", &cmd, &x, &y);


		if (cmd) {
			int xx, yy;
			scanf("%d%d", &xx, &yy);
			printf("%d\n", query(x, y, xx, yy));
		}
		else {
			int c;
			scanf("%d", &c);
			update(x, y, c - query(x, y, x, y));
		}
	}
	
	return 0;
}



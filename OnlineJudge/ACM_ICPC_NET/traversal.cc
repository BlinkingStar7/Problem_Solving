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

int n, pre[101], in[101];

void solve(int x, int y, int xx, int yy) {
	if (x == y) {
		printf("%d ", pre[x]);
		return ;
	}
	int pos = find(in+xx, in+yy+1, pre[x])-in;
	int leftNum = pos - xx, rightNum = yy - pos;
	if (leftNum) solve(x+1, x+leftNum, xx, pos-1);
	if (rightNum) solve(x+leftNum+1, y, pos+1, yy);
	printf("%d ", pre[x]);
}

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%d", pre+i);
		for (int i=0; i<n; ++i)
			scanf("%d", in+i);

		solve(0, n-1, 0, n-1);
		puts("");
	}

	return 0;
}



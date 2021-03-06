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
	int n, l, bef, len, m = 0;
	scanf("%d%d", &n, &l);
	scanf("%d%d", &len, &bef);

	for (int i=1; i<n; ++i) {
		int curLen, cur;
		scanf("%d%d", &curLen, &cur);
		if (cur != bef) {
			if ((l-curLen-len)/2 > m) m = (l-curLen-len)/2;
		}
		bef = cur; len = curLen;
	}

	printf("%d\n", m);
	return 0;
}



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

char a[2501], b[2501];
int aa, bb, back[2501], ans;
int main () {
	gets(a), gets(b);
	aa = strlen(a), bb = strlen(b);

	int m = 0;
	for (int i=1; i<bb; ++i) {
		while (m && b[i] != b[m]) m = back[m-1];
		if (b[i] == b[m])
			back[i] = ++m;
	}

	m = 0;
	for (int i=0; i<aa; ++i) {
		while (m && a[i] != b[m]) m = back[m-1];
		if (a[i] == b[m]) {
			if (++m == bb) {
				++ans;
				m = 0;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}



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

int x, n, a[1048576];
int main () {
	while (~scanf("%d", &x)) {
		if (x > 20) {
			printf("danger\n");
			continue;
		}

		bool ans = false;
		x *= 1e7;
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%d", a+i);
		sort(a, a+n);

		int aa = 0, bb = n-1;
		while (aa <= bb) {
			if (a[aa] + a[bb] == x) {
				printf("yes %d %d\n", a[aa], a[bb]);
				ans = true;
				break;
			}
			else if (a[aa] + a[bb] > x) --bb;
			else ++aa;
		}
		if (!ans) printf("danger\n");
	}
	return 0;
}



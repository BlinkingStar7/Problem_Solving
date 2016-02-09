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
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int Lds[4001], ans = 0, start = 2000, end = 2000;
		for (int i=0; i<n; ++i) {
			int t;
			scanf("%d", &t);
			int pos = lower_bound(Lds+start, Lds+end, t, greater<int>()) - Lds;
			if (pos == start) {
				--start;
				++ans;
				Lds[pos-1] = t;
			}
			else if (pos == end) {
				++end;
				++ans;
				Lds[pos] = t;
			}
			else Lds[pos] = t;

			for (int i=start; i<end; ++i)
				DPRINTF(("%d ", Lds[i]));
			DPRINTF(("\n"));
		}
		printf("%d\n", ans);
	}
	return 0;
}



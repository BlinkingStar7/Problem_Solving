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

struct car { char name[25]; int l, h; } C[10001];
int main () {
	int t;
	cin >> t;
	for (int tt=1; tt<=t; ++tt) {
		if (tt != 1) puts("");
		int d, q;
		cin >> d;

		for (int i=0; i<d; ++i) {
			scanf("%s%d%d",C[i].name, &C[i].l, &C[i].h);
		}

		cin >> q;
		for (int i=0; i<q; ++i) {
			vi ans;
			int p; scanf("%d", &p);
			for (int j=0; j<d && ans.size() < 2; ++j) {
				if (p >= C[j].l && p <= C[j].h)
					ans.push_back(j);
			}
			if (ans.size() != 1) printf("UNDETERMINED\n");
			else printf("%s\n", C[ans[0]].name);
		}

	}
	return 0;
}



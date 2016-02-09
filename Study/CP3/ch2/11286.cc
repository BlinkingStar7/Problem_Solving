#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int main () {
	int n;
	while(scanf("%d", &n)) {
		if (n == 0) break;
		map<vb, int> m;
		int best= 0;
		for (int i=0; i<n; ++i) {
			vb sel;
			sel.resize(401, false);
			for (int j=0; j<5; ++j) {
				int t;
				scanf("%d", &t);
				sel[t-100] = true;
			}
			for (int j=0; j<sel.size(); ++j)
				if (sel[j])
					DPRINTF(("%d ", j));
			DPRINTF(("\n"));
			best = max(++m[sel], best);
		}

		int cnt =0;
		for (map<vb, int>::iterator it = m.begin(); it != m.end(); ++it)
			if (it->second == best) ++cnt;
		printf("%d\n", cnt*best);
	}
	return 0;
}


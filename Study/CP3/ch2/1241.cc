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

#define MAX_N (1<<10)
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m, ans = 0;
		scanf("%d%d", &n, &m);

		vb b1(1<<n, true);
		for (int i=0; i<m; ++i) {
			int t;
			scanf("%d", &t);
			b1[t-1] = false;
		}

		for (int nn=n; nn>0; --nn) {
			int cur=(1<<nn)-1;
			
			DPRINTF(("when nn = %d\n", nn));
			for (int i=0; i<b1.size(); ++i) {
				DPRINTF(("%c", b1[i] ? 'o' : 'x'));
			}
			DPRINTF(("\n"));
			vb b2(1<<(nn-1), true);

			while (cur > 0) {
				if (b1[cur] ^ b1[cur-1]) ++ans;
				b2[cur/2] = b1[cur] || b1[cur-1];
				cur -= 2;
			}
			b1 = b2;
		}

		printf("%d\n", ans);
	}


	return 0;
}


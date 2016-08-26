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
typedef unsigned long long ull;

int main () {
	int n;
	scanf("%d", &n);

	for (int i=0; i<n; ++i) {
		int t;
		scanf("%d", &t);

		if (t == 1) {
			ull ans = 0;
			for (int j=0; j<8; ++j) {
				ans <<= 8;
				int tt;
				scanf("%d%*c", &tt);
				ans += tt;
			}
			printf("%llu\n", ans);
		}

		else {
			vi ans;
			ull tt;
			scanf("%llu", &tt);

			for (int j=0; j<8; ++j) {
				ans.push_back(tt%(1<<8));
				tt >>= 8;
			}

			for (int i=7; i>=0; --i) {
				printf("%d%c", ans[i], i ? '.' : '\n');
			}
		}
	}
	return 0;
}



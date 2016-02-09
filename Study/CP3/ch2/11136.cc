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
		multiset<int> bill;
		long long ans = 0;
		for (int i=0; i<n; ++i) {
			int t;
			scanf("%d",&t);
			for (int j=0; j<t; ++j) {
				int temp;
				scanf("%d",&temp);
				bill.insert(temp);
			}
			ans += *bill.rbegin() - *bill.begin();
			bill.erase(--bill.end()); bill.erase(bill.begin());
		}
		printf("%lld\n", ans);
	}

	return 0;
}


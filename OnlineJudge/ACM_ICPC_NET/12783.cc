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

int t, n, m, k, memo[1000001];
vi dd;
bool card[10];

int Solve (int k) {
	if (k == 1) return 0;

	int &ret = memo[k];
	if (ret != -1) return ret;

	ret = INF;

	for (int i=0; i<dd.size(); ++i) {
		if (k % dd[i] == 0)
			ret = min (ret, 1+Solve(k/dd[i]));
	}

	return ret;
}


int main () {

	scanf("%d", &t);
	for (int i=0; i<t; ++i) {
		memset(card, 0, sizeof(card));
		memset(memo, -1, sizeof(memo));
		
		scanf("%d", &n);
		for (int j=0; j<n; ++j) {
			int tt;
			scanf("%d", &tt);
			card[tt] = true;
		}

		scanf("%d", &m);
		for (int j=0; j<m; ++j) {
			scanf("%d", &k);

			if (k == 1) {
				printf("%d\n", card[1] ? 0 : -1);
				continue;
			}

			dd.clear();
			int sq = sqrt(k);

			for (int d=1; d<=sq; ++d) {
				if (k % d == 0) {
					int tmp = d;
					bool flag = true;
					while (tmp) {
						if (!card[tmp % 10]) { flag = false; break; }
						tmp /= 10;
					}

					if (flag && d != 1) dd.push_back(d);

					tmp = k/d;
					flag = true;

					while (tmp) {
						if (!card[tmp % 10]) { flag = false; break; }
						tmp /= 10;
					}
					if (flag) dd.push_back(k/d);
				}
			}

			int ans = Solve(k);
			printf("%d\n", ans == INF ? -1 : ans-1);
		}
	}

	return 0;
}



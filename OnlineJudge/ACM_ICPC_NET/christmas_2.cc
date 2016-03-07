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

const int MOD = 20091101;
int n, k, sum[100001], num[100001];

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i=1; i<=n; ++i) {
			scanf("%d", &sum[i]);
			sum[i] = (sum[i] + sum[i-1]) % k;
		}

		for (int i=0; i<=n; ++i)
			++num[sum[i]];

		int ans = 0;
		for (int i=0; i<k; ++i) ans = (ans + (long long) num[i]*(num[i]-1)/2) % MOD;
		printf("%d ", ans);

		int ret[100001], prev[100001];
		memset (ret, 0, sizeof(ret));
		memset (prev,-1, sizeof(prev));

		for (int i=0; i<=n; ++i) {
			ret[i] = i > 0 ? ret[i-1] : 0;
			int loc = prev[sum[i]];
			if (loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
			prev[sum[i]] = i;
		}
		
		printf("%d\n", ret[n]);			

	}

	return 0;
}



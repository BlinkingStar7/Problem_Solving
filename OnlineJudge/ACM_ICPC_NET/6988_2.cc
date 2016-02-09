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
	int n, tile[3001];
	bool num[1000001];

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", tile+i);
		num[tile[i]] = true;
	}

	long long ans = 0;
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j) {
			int d = tile[j] - tile[i];
			int c = 2;
			long long sum = tile[j] + tile[i];
			for (int k=tile[j]+d; k<=1000000 && num[k]; k+=d, ++c)
				sum += k;
			if (c > 2) ans = max(ans, sum);
		}

	printf("%lld\n", ans);

	return 0;
}

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
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	vi ans;
	for (int i=0; i<n; ++i) {
		int t;
		scanf("%d", &t);
		ans.push_back(-t);
	}

	sort(ans.begin(), ans.end());

	int nn = 0, cur = 0;
	for (int i=0; cur < m*k && i<n; ++i, ++nn)
		cur += -ans[i];

	if (cur < m*k)
		return printf("STRESS\n");

	printf("%d\n", nn);
		



	return 0;
}



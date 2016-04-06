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

struct ss {
	int g, v;
	bool operator < (const ss &a) const {
		return v < a.v;
	}
} stu[1000001];

int n, m, ans = INF, num[1001];

int main () {
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j) {
			scanf("%d", &stu[i*m+j].v);
			stu[i*m+j].g = i;
		}

	sort(stu, stu+n*m);

	int k = 0, r=0, l=0;
	while (r < n*m) {
		while (r < n*m && k < n) {
			if (num[stu[r].g] == 0) ++k;
			++num[stu[r].g];
			++r;
		}

		while (k == n) {
			ans = min (ans, stu[r-1].v - stu[l].v);
			if (num[stu[l].g]-- == 1) --k;
			++l;
		}
	}

	printf("%d\n", ans);
	return 0;
}



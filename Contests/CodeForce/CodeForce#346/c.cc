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

int List[100001];
int main () {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i)
		scanf("%d", &List[i]);
	sort(List, List+n);

	int index = 0;
	vi ans;
	for (int cur = 1; cur <= m; ++cur) {
		if (List[index] == cur) ++index;
		else {
			m -= cur;
			ans.push_back(cur);
		}
	}
	printf("%d\n", ans.size());
	for (int i=0; i<ans.size(); ++i)
		printf("%d ", ans[i]);
	return 0;
}



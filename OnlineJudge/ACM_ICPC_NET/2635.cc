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
	int n;
	scanf("%d", &n);
	int best = 1, num = 1;

	for (int i=1; i<=n; ++i) {
		int bef = i, cur = n - i, cand = 1;
		while (cur >= 0) {
			++cand;
			int temp = cur;
			cur = bef - cur;
			bef = temp;
		}
		if (cand > best) {
			best = cand;
			num = i;
		}
	}

	printf("%d\n", best+1);
	int bef = n, cur = num;
	printf("%d %d", bef, cur);
	for (int i=0; i<best-1; ++i) {
		int temp = cur;
		cur = bef - cur;
		bef = temp;
		printf(" %d", cur);
	}
	puts("");

	return 0;
}



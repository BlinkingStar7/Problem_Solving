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
	for (int i=0; i<3; ++i) {
		int n; scanf("%d", &n);
		int best = 0, bef = -1, num = 0;
		while (n) {
			int cur = n%10;
			if (cur != bef) {
				best = max(best, num);
				num = 1;
				bef = cur;
			}
			else 
				++num;
			n/=10;
		}
		best = max(best, num);
		printf("%d\n", best);
	}
	return 0;
}



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

int n, k;
int main () {
	scanf("%d%d", &n, &k);
	int chunk = 0;
	for (int i=0; i<k; ++i) {
		int m,t;
		scanf("%d", &m);

		scanf("%d", &t);
		if (t == 1) {
			int j;
			for (j=1; j<m; ++j) {
				scanf("%d", &t);
				if (!chunk && t != j+1) chunk = j;
			}
			if (!chunk && t != j+1) chunk = j;
		}
		else
			for (int j=1; j<m; ++j)
				scanf("%*d");
	}

	printf("%d\n", n-k-chunk+1 + n-chunk);
	return 0;
}



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
	int best = -1, ans = -1;
	for (int i=0; i<n; ++i) {
		int a[5];
		for (int j=0; j<5; ++j)
			scanf("%d", &a[j]);
		for (int x=0; x<5; ++x)
			for (int y=x+1; y<5; ++y)
				for (int z=y+1; z<5; ++z) {
					int cand = a[x]+a[y]+a[z];
					if (cand%10 > best) {
						best = cand%10;
						ans = i+1;
					}
				}
	}
	printf("%d\n", ans);
	return 0;
}



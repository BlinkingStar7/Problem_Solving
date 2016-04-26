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

int n, q, d, dd[2], ans[1000001];
int main () {
	bool even = true;
	scanf("%d%d", &n, &q);
	for (int i=0; i<q; ++i) {
		int t, x;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d", &x);
			d = (d+n+x)%n;
			if (x%2) even = !even;
		}
		else {
			if (even) {
				dd[0]++;
				dd[1]--;
			}
			else {
				dd[0]--;
				dd[1]++;
			}
			even = !even;
		}
	}

	for (int i=0; i<2; ++i)
		while (dd[i] < 0) dd[i] += n;

	for (int i=0; i<n; ++i) {
		int pos = (i + d + dd[i%2])%n;
		ans[pos] = i+1;
	}

	for (int i=0; i<n; ++i)
		printf("%d%c",ans[i],i==n-1? '\n' : ' ');

	return 0;
}



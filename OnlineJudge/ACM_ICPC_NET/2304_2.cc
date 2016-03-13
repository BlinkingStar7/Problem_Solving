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
	int n, s[1001]={0}, r[1001]={0};
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		int ll,hh;
		scanf("%d%d",&ll,&hh);
		s[ll] = hh;
	}

	int c = 0;
	for (int i=1; i<=1000; ++i) {
		c = max(c, s[i]);
		r[i] = c;
	}

	c = 0;
	for (int i=1000; i>=1; --i) {
		if (s[i] == r[i]) break;
		c = max(c, s[i]);
		r[i] = c;
	}

	int ans = 0;
	for (int i=1; i<=1000; ++i)
		ans += r[i];
	printf("%d\n", ans);


	return 0;
}



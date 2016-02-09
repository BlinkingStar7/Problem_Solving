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
	int n, a = 1, aa = 1 ;
	scanf("%d", &n);

	for (int i=1; i<=n; ++i) {
		printf("a[%d] = %d/%d\n", i, a, aa);
		int nexta = aa;
		int nextaa = 2*(a/aa)*aa - a + aa;
		a = nexta;
		aa = nextaa;
	}

	return 0;
}



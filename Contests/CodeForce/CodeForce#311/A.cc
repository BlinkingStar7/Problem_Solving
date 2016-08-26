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
	int n, a[3][2];
	scanf("%d", &n);
	for (int i=0; i<3; ++i) for (int j=0; j<2; ++j)
		scanf("%d", &a[i][j]);

	int aa = min(n-a[1][0]-a[2][0], a[0][1]);
	int bb = min(n-aa-a[2][0], a[1][1]);
	printf("%d %d %d\n", aa, bb, n-aa-bb);
	return 0;
}



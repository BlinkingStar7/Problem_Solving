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

typedef long long LL;
int main () {
	int t;
	cin >> t;
	while (t--) {
		LL a, b, c;
		cin >> a >> b >> c;
		bool sol = false;
		for (LL x = -100; x<=100 && !sol; ++x) if (x*x <= c)
			for (LL y = x; y<=100 && !sol; ++y) if (y != x && x*x+y*y <= c) {
				LL z = a - (x+y);
				if (x == y || y == z || z < y) continue;
				if (x*y*z == b && x*x+y*y+z*z == c) {
					sol = true;
					printf("%d %d %d\n", x, y, z);
				}
			}
		if (!sol) printf("No solution.\n");
	}
	return 0;
}




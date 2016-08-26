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
typedef long long ll;
typedef unsigned long long ull;

int main () {
	int a, b, n;
	scanf("%d%d%d", &a, &b, &n);
	
	int bestD2 = 100001, bestV = 1;
	for (int i=0; i<n; ++i) {
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		v *= v;
		
		int tempD2 = (x-a)*(x-a)+(y-b)*(y-b);
		if (tempD2*bestV < bestD2*v) {
			bestD2 = tempD2;
			bestV = v;
		}
	}

	printf("%.12lf\n", sqrt(bestD2)/ sqrt(bestV));
	return 0;
}



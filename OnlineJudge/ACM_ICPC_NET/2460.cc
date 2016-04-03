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
	int sum=0, best = 0;
	for (int i=0; i<10; ++i) {
		int a, b;
		scanf("%d%d", &a,&b);
		sum += (b - a);
		best = max(best, sum);
	}
	printf("%d\n", best);
	return 0;
}



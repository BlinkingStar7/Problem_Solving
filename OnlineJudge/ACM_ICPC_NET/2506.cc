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
	int n; scanf("%d", &n);
	int sum=0, cur=0;
	for (int i=0; i<n; ++i) {
		int t;
		scanf("%d", &t);
		if (t) sum += ++cur;
		else cur = 0;
	}
	printf("%d\n", sum);
	return 0;
}



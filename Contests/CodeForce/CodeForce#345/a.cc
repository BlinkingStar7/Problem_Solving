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
	int a, b;
	scanf("%d%d", &a, &b);

	int ans = 0;
	while (1) {
		if (a == 0 || b == 0 || (a == 1 && b == 1)) break;
		if (a > b) swap (a, b);
		a += 1; b -= 2;
		++ans;
	}

	printf("%d\n", ans);
	return 0;
}



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
	int a, b, c, d; scanf("%d%d%d%d", &a,&b,&c,&d);
	c += d;
	b += c/60; c %= 60;
	a += b/60; b %= 60;
	a %= 24;
	printf("%d %d %d\n", a, b, c);
	return 0;
}



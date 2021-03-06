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

int gcd (int a, int b) {
	return a == 0 ? b : gcd(b%a, a);
}

int main () {
	int a, b;
	scanf("%d%d", &a, &b);
	int g=gcd(a, b), l=a*b/g;
	printf("%d\n%d\n", g, l);
	return 0;
}



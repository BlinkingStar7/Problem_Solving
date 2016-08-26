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

long long gcd (long long a, long long b) {
	return b ? gcd (b, a%b) : a;
}

int main () {
	long long a, b;
	scanf("%lld %lld", &a, &b);

	long long d = b - a, u;
	u = (int)sqrt(b) - (int)sqrt(a);

	if (u == 0) {
		printf("0\n");
		return 0;
	}

	long long g = gcd (d, u);

	printf("%lld/%lld\n", u/g, d/g);
	return 0;
}



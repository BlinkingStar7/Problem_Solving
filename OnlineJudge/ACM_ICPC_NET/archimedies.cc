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

bool isSame(double a, double b) {
	return abs(b-a) < 1e-9 || abs(b-a) <= max(abs(a), abs(b))*1e-9;
}

int main () {
	int c, t;
	scanf("%d%d", &c, &t);
	double lo=0.0, hi = t;

	while (!isSame(lo, hi)) {
		double mid = (lo+hi)/2;
		if (mid*(log(mid)/log(2.0)) >= (double)t/c) hi = mid;
		else lo = mid;
	}

	printf("%lf\n", hi);
	lo=0.0, hi = t+1;

	while (!isSame(lo, hi)) {
		double mid = (lo+hi)/2;
		if (mid*(log(mid)/log(2.0)) >= (double)t/c) hi = mid;
		else lo = mid;
	}

	printf("%lf\n", hi);
	return 0;
}



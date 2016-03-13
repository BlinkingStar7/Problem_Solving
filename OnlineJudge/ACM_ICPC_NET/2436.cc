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

int gcd(int a, int b) {
	return a == 0 ? b : gcd(b%a, a);
}

int main () {
	int G, L;
	scanf("%d%d", &G, &L);
	int ab = L/G;
	int sqrt_ab = sqrt(ab), best = 123456789, ans = -1;
	for (int a=1; a<=sqrt_ab; ++a) {
		int b = ab/a;
		if (ab%a == 0 && gcd(a, b) == 1) {
			if (a+b < best) ans = a;
		}
	}

	printf("%d %d\n", G*ans, G*(ab/ans));
	return 0;
}



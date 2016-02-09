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
	const long long MAX = 1000000LL * 2000;
	const long long le6 = 1000000LL;

	for (long long a=1; a<=2000/4 && a*a*a*a<=MAX; ++a) 
		for (long long b=a; b<=(2000-a)/3 && a*b*b*b<=MAX; ++b) {
			for (long long c=b; c<=(2000-a-b)/2 && a*b*c*c<=MAX; ++c) {
				long long sum = a+b+c, pro = a*b*c;
				if (pro <= le6) continue;
				if (sum*le6 % (pro - le6)) continue;
				long long d = (sum*le6/(pro-le6));
				if (sum + d > 2000) continue;
				if (d < c) continue;
				printf("%d.%02d %d.%02d %d.%02d %d.%02d\n", a/100, a%100, b/100, b%100, c/100, c%100, d/100, d%100);
			}
		}

	return 0;
}



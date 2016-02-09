// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <ctime>

#define Inf 2147483647
#define Pi acos(-1.0)
#define N 1000000
#define LL long long
#define F(i, n) for( int i = (0); i < (n); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Set(a, s) memset(a, s, sizeof (a))
inline LL Power(int b, int p) { LL r = 1; for ( int i = 1; i <= p; i++ ) r *= b; return r; }

using namespace std;

struct node {
	char companyName [80 + 20];
	int compliance;
	int price;
	int r;
} a [10000];

bool cmp(node p, node q) {

	// greater compliance should come first
	if (p.compliance > q.compliance) return true;

	if (p.compliance == q.compliance) {
		// lower price should come first
		if (p.price < q.price) return true;
	}

	return false;
}

int main ()
{
	int n;
	int p;

	bool blank = false;

	int cases = 0;

	while ( scanf ("%d %d", &n, &p) != EOF ) {
		getchar();

		if ( n == 0 && p == 0 ) break;

		char itemName [80 + 20];

		// don't need this input data
		F(i, n) {
			gets(itemName);
		}

		double price;

		F(i, p) {
			gets(a [i].companyName);
			scanf ("%lf %d", &price, &a [i].r);

			// keeping the price integer
			a [i].price = (int) (price * 100);
			getchar();

			// keeping the compliance integer
			a [i].compliance = (a [i].r * N) / n;

			// don't need this input data
			F(j, a [i].r) {
				gets(itemName);
			}
		}

		sort(a, a + p, cmp);

		if (blank) printf ("\n");
		blank = true;

		printf ("RFP #%d\n%s\n", ++cases, a [0].companyName);
	}

	return 0;
}

// @END_OF_SOURCE_CODE

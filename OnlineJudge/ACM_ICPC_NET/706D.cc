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
typedef long long ll;
typedef unsigned long long ull;

int Q;

int main () {
	scanf("%d ", &Q);
	multiset<int> s;
	s.insert(0);

	for (int i=0; i<Q; ++i) {
		int x; char c;
		scanf(" %c %d", &c, &x);

		if (c == '+') s.insert(x);
		else if (c == '-') { s.erase(s.find(x)); }
		else {
			multiset<int>::iterator lo = s.begin(), hi = s.end();

			//printf("Debug\n");
			//for (multiset<int>::iterator it = s.begin(); it != s.end(); it++)
			//	printf("%d ", *it);

			for (ll p = 1<<31L, sum = 0; p; p>>=1) {
				if (p & x) {	// to find 0
					multiset<int>::iterator temp = lower_bound(lo, hi, sum + p);
					if (temp == lo)
						sum += p;
					else 
						hi = temp;
				}
				else {
					multiset<int>::iterator temp = lower_bound(lo, hi, sum + p);
					if (temp == hi)
						;
					else {
						sum += p;
						lo = temp;
					}
				}

				if (lo == hi) break;
			}

			printf("%d\n", (*lo)^x);
		}
	}
	return 0;
}



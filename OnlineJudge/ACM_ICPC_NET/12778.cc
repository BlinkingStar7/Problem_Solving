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
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		int nn;
		char c;
		scanf("%d %c", &nn, &c);

		
		for (int i=0; i<nn; ++i) {
			if (c == 'C') {
				char t;
				scanf(" %c", &t);
				printf("%d%c", t-'A'+1, i == nn-1 ? '\n' : ' ' );
			}
			else {
				int t;
				scanf("%d ", &t);
				printf("%c%c", t+'A'-1, i == nn-1 ? '\n' : ' ' );
			}
				
		}
	}

	return 0;
}



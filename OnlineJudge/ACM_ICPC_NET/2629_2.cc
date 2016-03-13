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

int n, m, d[30001] = {}, counter = 2;
inline bool isSafe(int a) {
	return a>=0 && a<=30000 && d[a];
}
int main () {
	d[15000] = 1;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		int p;
		scanf("%d", &p);
		for (int j=30000; j>=0; --j) if(!d[j]){
			if (isSafe(j+p) && d[j+p]<counter) d[j] = counter;
			if (isSafe(j-p) && d[j-p]<counter) d[j] = counter;
		}
		++counter;
	}
	scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		int t;
		scanf("%d", &t);
		printf("%c ", d[t+15000] ? 'Y' : 'N');
	}

	return 0;
}



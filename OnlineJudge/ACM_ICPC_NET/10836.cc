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

int a[1401];
int main () {
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i=0; i<n; ++i) {
		int grow[3];
		for (int j=0; j<3; ++j) 
			scanf("%d", &grow[j]);
		a[grow[0]]++;
		a[grow[0]+grow[1]]++;
	}

	for (int i=1; i<2*m-1; ++i)
		a[i] += a[i-1];

	for (int i=0; i<m; ++i) {
		printf("%d", a[(m-1)-i]+1);
		for (int j=m; j<2*m-1; ++j)
			printf(" %d", a[j]+1);
		puts("");
	}
	return 0;
}



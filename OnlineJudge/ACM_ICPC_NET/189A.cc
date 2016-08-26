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

int main () {
	int a[4];
	for (int i=0; i<4; ++i)
		scanf("%d", a+i);

	int d[4001];
	memset(d, 0, sizeof(d));

	d[0] = 1;
	for (int i=1; i<=a[0]; ++i) for (int j=1; j<4; ++j)
		if (i-a[j] >= 0 && d[i-a[j]]) {
			d[i] = max(d[i], d[i-a[j]]+1);
		}

	printf("%d\n", d[a[0]]-1);
	return 0;
}



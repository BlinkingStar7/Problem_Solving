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
	int n, a[1001];
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);
	int sum=0;
	for (int i=0; i<n; ++i)
		if (a[i] > sum+1)
			break;
		else sum += a[i];

	printf("%d\n", sum+1);
	return 0;
}



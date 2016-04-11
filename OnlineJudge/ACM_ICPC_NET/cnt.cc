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

int n, a[100], f[100], s[100], mmin, mmax;
int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", a+i);
	}

	mmin = *min_element(a, a+n);
	mmax = *max_element(a, a+n);

	for (int i=0; i<n; ++i)
		f[a[i]-mmin]++;
	
	for (int i=1; i<mmax-mmin+1; ++i)
		f[i] += f[i-1];

	for (int i=n-1; i>=0; --i)
		s[--f[a[i]-mmin]] = a[i];
	for (int i=0; i<n; ++i)
		printf("%d ", s[i]);


	return 0;
}



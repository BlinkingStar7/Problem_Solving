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

int n, b[3001], t, h, s[3001], d[3001];
int main () {
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
		scanf("%d", b+i);

	scanf("%d%d", &t, &h);
	sort(b+1, b+n+1);
	for (int i=1; i<=n; ++i)
		s[i] = s[i-1] + b[i];

	for (int i=1; i<=n; ++i) {
		int &cur = d[i];
		cur = s[i]*t;
		for (int j=1; j<=i; ++j) {
			int mid = (i+j)/2, m = b[mid];
			int add = (m*(mid-j+1)-(s[mid]-s[j-1])) + ((s[i]-s[mid])-m*(i-mid));
			cur = min (cur, d[j-1] + h + add*t);
		}
	}

	printf("%d\n", d[n]);
	return 0;
}



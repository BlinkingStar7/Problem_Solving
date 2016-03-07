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

int a[501], b[501], c[501];
int main () {
	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d", a+i);
		a[i]--;
	}

	a[0] = a[n];
	int num = 0, start = -1;
	int last, first;
	bool flag = false;

	for (int i=n; i>=1; --i) {
		if (a[i] != (a[i-1] + 1) % n) {
			++num;
			if (!flag) start = i;
		}
		else if (start != -1) flag = true;
	}

	last = n - (start - 1);

	for (int i=1; i<=n; ++i) {
		int pos = (start+i-1) > n ? (start+i-1-n) : (start+i-1);
		b[i] = a[pos];
	}

	for (int i=1; i<=num-1; ++i)
		c[i] = b[num-i];
	for (int i=num; i<=n; ++i)
		c[i] = b[i];

	for (int i=1; i<=n; ++i)
		if (c[i] == 0) {
			first =  n-(i-1);
			break;
		}

	printf("%d\n", first);
	printf("%d %d\n", 1, num-1);
	printf("%d\n", n - (start - 1));

	return 0;
}



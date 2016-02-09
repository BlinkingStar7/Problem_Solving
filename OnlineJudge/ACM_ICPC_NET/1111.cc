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
	int n, a[51];
	cin >> n;
	for (int i=0; i<n; ++i) scanf("%d", a+i);

	if (n == 1)
		printf("A\n");
	else if (n == 2) {
		if (a[0] == a[1]) printf("%d\n", a[0]);
		else printf("A\n");
	}
	else {
		if (a[0] == a[1]) {
			bool flag = true;
			for (int i=0; i<n; ++i)
				if (a[i] != a[0]) {
					flag = false;
					break;
				}
			if (flag) printf("%d\n", a[0]);
			else printf("B\n");
		}
		else {
			int x, y;
			bool flag = true;
			if ((a[2]-a[1])%(a[1]-a[0])) flag = false;
			x = (a[2]-a[1])/(a[1]-a[0]);
			y = a[1] - x*a[0];

			for (int i=0; i<n-1; ++i)
				if (a[i+1] != a[i]*x+y) flag = false;
			if (flag) printf("%d\n", a[n-1]*x+y);
			else printf("B\n");
		}
	}
	return 0;

}



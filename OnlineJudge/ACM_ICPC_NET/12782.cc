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
		string a, b;
		cin >> a >> b;
		int x=0, y=0;

		for (int j=0; j<a.size(); ++j) {
			if (a[j] != b[j])
				a[j] == '0' ? ++x : ++y;
		}

		printf("%d\n", x + y - min(x, y));
	}

	return 0;
}



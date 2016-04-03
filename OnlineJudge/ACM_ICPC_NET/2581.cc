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

int m, n;
bool compo[10001];

int main () {
	int sum = 0, mmin = -1;
	scanf("%d%d",&m, &n);

	for (int i=2; i<=n; ++i) {
		if (!compo[i]) {
			for (int j=i*i; j<=n; j+=i)
				compo[j] = true;
			if (i >= m) {
				sum += i;
				if (mmin == -1) mmin = i;
			}

		}
	}
	printf("%d\n%d\n", sum, mmin);
	return 0;
}



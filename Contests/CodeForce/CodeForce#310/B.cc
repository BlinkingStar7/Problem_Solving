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
int n;
int main () {
	scanf("%d", &n);
	bool ans = true;
	int bef = -1;
	for (int i=0; i<n;++i) {
		int t;
		scanf("%d", &t);
		if (bef == -1) {
			bef = t;
		}
		else if (i%2) {
			if ((t+bef)%n != i) {
				ans = false;
				break;
			}
		}
		else if ((t-bef+n)%n != i) {
			ans = false;
			break;
		}
	}
	printf("%s\n", ans ? "Yes" : "No");
	return 0;
}



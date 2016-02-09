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
	cin >> n;
	long long ans = 0;
	int oddNum = 0, mmin = 1e9+1;
	for (int i=0; i<n; ++i) {
		int t;
		scanf("%d", &t);
		ans += t;
		if (t%2) {
			mmin = min(mmin, t);
			++oddNum;
		}
	}
	if (oddNum%2) ans -= mmin;
	cout << ans << endl;
	return 0;
}



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
	int n, a=0, b=0;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		int t, tt;
		cin >> t >> tt;
		if (t >= tt) ++a;
		if (tt >= t) ++b;
	}

	if (a > b) cout << "Mishka" << endl;
	else if (a == b) cout << "Friendship is magic!^^" << endl;
	else cout << "Chris" << endl;
	return 0;
}



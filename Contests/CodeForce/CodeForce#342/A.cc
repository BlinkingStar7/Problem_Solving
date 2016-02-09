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
	long long n, a, b, c;
	cin >> n >> a >> b >> c;

	if (a <= (b-c) || n < b) cout << n/a << endl;
	else {
		long long num = (n-b)/(b-c) + 1;
		n -= num*(b-c);
		num += n/a;
		cout << num << endl;
	}

	return 0;
}



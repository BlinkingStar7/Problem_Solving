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

const int MAX = 1100000;
int N;
ll V, dataMul[MAX], dataAdd[MAX];

void update (int p, ll mul, ll add) {
	for (; p <= MAX; p += p & -p) {
		dataMul[p] += mul;
		dataAdd[p] += add;
	}
}

ll query (int p) {
	int ori = p;
	ll mul = 0, add = 0;
	for (; p; p -= p & -p) {
		mul += dataMul[p];
		add += dataAdd[p];
	}
	return ori*mul + add;
}

int main () {
	ios::sync_with_stdio(false);

	cin >> N;
	ll total = 0;
	for (int i=0; i<N; ++i) {
		ll b, h, w, d;
		cin >> b >> h >> w >> d;

		update (b+1, w*d, -(ll)b*w*d);
		update (b+h, -w*d, (ll)(b+h)*w*d);
		total += h*w*d;
	}

	cin >> V;

	if (total > V) {
		cout << "OVERFLOW" << endl;
		return 0;
	}

	for (int i=1; i<25; ++i) {
		DPRINTF(("%d : %lld\n", i, query(i)-query(i-1)));
	}

	double lo = 0, hi = MAX;
	for (int i=0; i<100; ++i) {
		double mid = (lo + hi)/2;

		double left = mid - (int)mid;
		double vol = query(mid) + left*(query(mid+1) - query(mid));

		DPRINTF(("mid : %lf, vol : %lf\n", mid, vol));

		if (vol >= V) hi = mid;
		else lo = mid;
	}

	printf("%.2lf\n", lo);
	return 0;
}

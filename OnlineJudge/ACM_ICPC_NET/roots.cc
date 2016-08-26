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

int t, n;
double f(vector<double>& c, double x) {
	double ret = 0;
	for (int i=c.size()-1; i>=0; --i) {
		ret *= x;
		ret += c[i];
	}
	return ret;
}


vector<double> solve(vector<double>& c, int d) {
	vector<double> ret, peak, diff;
	if (d == 0) return ret;

	for (int i=1; i<c.size(); ++i)
		diff.push_back(c[i]*i);

	peak = solve(diff, d-1);
	peak.push_back(11);

	for (int i=0; i<peak.size(); ++i) {
		double lo = i ? peak[i-1] : -11, hi = peak[i];
		for (int it=0; it<100; ++it) {
			double mid = (lo+hi)/2;
			if (f(c, lo) * f(c, mid) > 0) lo = mid;
			else hi = mid;
		}
		ret.push_back((lo+hi)/2);
	}

	return ret;
}
	
int main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vector<double> coeff(n+1), ret;

		for (int i=n; i>=0; --i)
			scanf("%lf", &coeff[i]);

		ret = solve(coeff, n);
		for (int i=0; i<ret.size(); ++i)
			printf("%lf ", ret[i]);
		puts("");
	}

	return 0;
}



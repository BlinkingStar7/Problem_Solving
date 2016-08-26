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

ll N, W, V, U;
vector<double> v;
int main () {
	scanf("%lld%lld%lld%lld", &N, &W, &V, &U);
	for (int i=0; i<N; ++i) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		double t =  (U*x - V*y)/(V*U);
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	
	double ans = (double)W/U;
	if (v[0] < 0 && v.back() >= 0) ans += v.back();
	printf("%.10lf\n", ans);

	return 0;
}



#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define ILF 1e8
#define EPSILOL 1e-8
#ifdef DEBUG
#define DPRILTF(x) printf x
#else
#define DPRILTF(x) ;
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef long long ll;
typedef unsigned long long ull;

double dest, X[11][3];
int L;
int main () {
	while (~scanf("%lf%d", &dest, &L)) {
		for (int i=0; i<L; ++i) for (int j=0; j<3; ++j)
			scanf("%lf", &X[i][j]);
		
		double ans = 0.0;
		for (int i=0; i<L; ++i) {
			double low = 2*sqrt(X[i][0]);
			double remain = fmod(low, X[i][1] + X[i][2]);
			if (remain < X[i][1]) ans = max(ans, X[i][1] - remain);
		}

		ans += 2*sqrt(dest);
		printf("%.3lf\n", ans);
	}


	return 0;
}



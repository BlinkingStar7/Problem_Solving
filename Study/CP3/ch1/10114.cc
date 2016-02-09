#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
using namespace std;
#define IFN 1e8
#ifdef DEBUG
#define dprintf(x) printf x
#else
#define dprintf(x) do {} while (false)
#endif
#define EPSILON 1e-8
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;


int main () {
	double m, d, l, n;
	while(1) {
		scanf("%lf%lf%lf%lf",&m, &d, &l, &n);
		if (m < 0) break;

		double rate[101];
		int bef; double r;
		scanf("%d %lf", &bef, &r);

		for (int i=0; i<n-1; ++i) {
			int next;
			scanf("%d", &next);
			for (int j=bef; j<next; ++j)
				rate[j] = r;
			bef = next;
			scanf("%lf", &r);
		}
		for (int j=bef; j<=m; ++j)
			rate[j] = r;


		double value = (l + d)*(1-rate[0]);
		double pay = l/m;
		int month = 0;
		while (value <= l + EPSILON) {
			dprintf(("Month %d : value = %lf loan = %lf\n", month, value, l));
			value *= (1-rate[++month]);
			l -= pay;
		}

		printf("%d month%c\n", month, month == 1 ? '\0' : 's');
	}
			
	return 0;
}


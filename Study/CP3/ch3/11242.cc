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

bool compare (const pii& a, const pii& b) {
	return a.first*b.second < a.second*b.first;
}


int main () {
	int f, r, n[1001], m[1001];
	while(1) {
		scanf("%d", &f);
		if (!f) break;
		scanf("%d", &r);
		for (int i=0; i<f; ++i) scanf("%d", m+i);
		for (int i=0; i<r; ++i) scanf("%d", n+i);
		
		vpii d;
		for (int a=0; a<r; ++a) for (int b=0; b<f; ++b)
			d.push_back(make_pair(n[a], m[b]));
		sort(d.begin(), d.end(), compare);

		double ans = 0;
		for (int i=1; i<d.size(); ++i) {
			double cand = (double)d[i].first*d[i-1].second/(d[i].second*d[i-1].first);
			ans = max(ans, cand);
		}

		printf("%.2lf\n", ans);
	}
	return 0;
}



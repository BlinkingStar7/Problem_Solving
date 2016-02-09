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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vpii p;

		for (int i=0; i<n; ++i) {
			int r, c, num;
			scanf("%d%d%d", &r, &c, &num);
			p.push_back(make_pair(r*5+c, num));
		}

		vi office(5), ans;
		int best = INF;
		for (office[0]=0; office[0]<=24-4; ++office[0]) for (office[1]=office[0]+1; office[1]<=24-3; ++office[1]) for (office[2]=office[1]+1; office[2]<=24-2; ++office[2])
			for (office[3]=office[2]+1; office[3]<=24-1; ++office[3]) for (office[4]=office[3]+1; office[4]<=24; ++office[4]) {
				int total = 0;
				for (int i=0; i<p.size(); ++i) {
					int dist = INF;
					for (int j=0; j<5; ++j) {
						int r=office[j]/5, c=office[j]%5, rr=p[i].first/5, cc=p[i].first%5;
						dist = min(dist, (abs(r-rr)+abs(c-cc))*p[i].second);
					}
					total += dist;
				}
				if (total < best) {
					best = total;
					ans = office;
				}
			}

		for (int i=0; i<5; ++i)
			printf("%d%c",ans[i], i==4 ? '\n' : ' ');
	}

	return 0;
}



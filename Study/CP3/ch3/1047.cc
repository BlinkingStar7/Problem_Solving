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
	int n, m, t=1;
	while (scanf("%d%d", &n,&m) && (n || m)) {
		int people[21];
		for (int i=0; i<n; ++i) scanf("%d", people+i);
		
		int setNum; scanf("%d", &setNum);
		vpii subset(setNum);

		for (int i=0; i<subset.size(); ++i) {
			int num; scanf("%d", &num);
			int set = 0;
			for (int j=0; j<num; ++j) {
				int t;
				scanf("%d", &t);
				set |= 1<<(t-1);
			}
			int t; scanf("%d", &t);
			subset[i] = make_pair(set, t);
		}

		int best = -INF, ans;
		for (int selected=0; selected<(1<<n); ++selected) if (__builtin_popcount(selected) == m) {
			int sum = 0;
			for (int i=0; i<n; ++i) if (selected & (1<<i)) sum += people[i];

			for (int i=0; i<subset.size(); ++i) {
				int intsc = selected & subset[i].first;
				int num = __builtin_popcount(intsc); 
				if (num == 0 || num == 1) continue;
				sum -= subset[i].second * (num-1);
			}

			if (sum > best) {
				best = sum;
				ans = selected;
			}
		}

		printf("Case Number  %d\n", t++);
		printf("Number of Customers: %d\n", best);
		printf("Locations recommended:");
		for (int i=0; i<n; ++i)
			if (ans & (1<<i)) printf(" %d", i+1);
		printf("\n\n");
	}
				
	return 0;
}



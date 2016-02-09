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

int X, wind[10][1001], DP[1001][10];
int main () {
	int t;
	cin >> t;
	for  (int tt=1; tt<=t; ++tt) {
		cin >> X;
		X/=100;
		for (int i=9; i>=0; --i) for (int j=0; j<X; ++j)
			scanf("%d", &wind[i][j]);

		for (int dist=X; dist>=0; --dist)
			for (int alt=9; alt>=0; --alt) {
				int &cur = DP[dist][alt];
				if (dist == X) cur = alt == 0 ? 0 : INF;
				else {
					cur = DP[dist+1][alt] + 30 - wind[alt][dist];
					if (alt>0) cur = min(cur, DP[dist+1][alt-1] + 20 - wind[alt][dist]);
					if (alt<9) cur = min(cur, DP[dist+1][alt+1] + 60 - wind[alt][dist]);
				}
			}
		printf("%d\n", DP[0][0]);
		puts("");
	}
					

	return 0;
}



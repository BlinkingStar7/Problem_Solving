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

const int x = 100000;
bool dp[3][200001];
int main () {
	scanf("%d", &n);

	for (int i=0; i<n; ++i) {
		int t; scanf("%d", &t);
		dp[0][t+x] = true;
		for (int j=0; j<=2*x; ++j) if (j-t >= -x && j-t <= x)
			dp[1][j+x] ||= dp[0][j-
	return 0;
}



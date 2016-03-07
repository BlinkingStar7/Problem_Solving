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
	int n;
	vpii ball[2002];
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		int c, s;
		scanf("%d%d", &c,&s);
		ball[s].push_back(make_pair(c, i));
	}

	vi sub(n+1, 0), ans(n);

	long long sum = 0;
	for (int i=2; i<=2000; ++i) {
		sum += ball[i-1].size() * (i-1);
		for (int j=0; j<ball[i-1].size(); ++j)
			sub[ball[i-1][j].first] += i-1;
		for (int j=0; j<ball[i].size(); ++j)
			ans[ball[i][j].second] = sum - sub[ball[i][j].first];
	}

	for (int i=0; i<n; ++i)
		printf("%d\n", ans[i]);

	return 0;
}



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
		int n, p, bar[21];
		scanf("%d%d",&n,&p);
		for (int i=0; i<p; ++i) scanf("%d", bar+i);

		bool sol = false;
		for (int i=0; i<(1<<p) && !sol; ++i) {
			int sum = 0;
			for (int j=0; j<p; ++j)
				if (i & (1<<j)) sum += bar[j];
			if (sum == n) sol = true;
		}
		printf("%s\n", sol ? "YES" : "NO");
	}

	return 0;
}



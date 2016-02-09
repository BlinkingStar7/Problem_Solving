#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int main () {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		unordered_map<int, int> m;
		int start = 1, len = 0;
		for (int i=1; i<=n; ++i) {
			int cur;
			scanf("%d", &cur);
			int bef = m[cur];
			if (bef >= start) {
				len = max(len, i-start);
				start = bef+1;
			}
			m[cur] = i;
		}
		len = max(len, n+1-start);
		printf("%d\n", len);
	}


	return 0;
}


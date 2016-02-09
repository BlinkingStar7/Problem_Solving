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
	int n, m;
	unordered_set<int> cd;
	while(scanf("%d%d",&n,&m) && (n || m)) {
		cd.clear();
		for (int i=0; i<n; ++i) {
			int temp;
			scanf("%d", &temp);
			cd.insert(temp);
		}
		int ans=0;
		for (int i=0; i<m; ++i) {
			int temp;
			scanf("%d", &temp);
			if (cd.find(temp) != cd.end())
				++ans;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}


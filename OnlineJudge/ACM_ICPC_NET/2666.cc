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
	scanf("%d%d%d",&n,&a,&b);
	int door = (1<<n) - 1;
	door -= (1<<(a-1));
	door -= (1<<(b-1));

	scanf("%d", &nn);
	int ans = 0;
	memset(memo, -1, sizeof(memo));
	for (int i=0; i<nn; ++i) {
		int t;
		scanf("%d", &t);
		pii ret = solve(door, t);
		ans += ret.first;
		door = ret.second;
	}

	return 0;
}



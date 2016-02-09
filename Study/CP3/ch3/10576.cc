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

int s, d;
int solve(int num, int (&p)[13]) {
	if (num == 12) {
		int ret = 0;
		for (int i=0; i<12; ++i) ret += p[i];
		return ret;
	}
	
	if (num >= 5) {
		int sum=0;
		for (int i=1; i<=5; ++i) sum += p[num-i];
		if (sum >= 0) return -INF;
	}

	int ret = -INF;
	p[num] = s;
	ret = max(ret, solve(num+1, p));
	p[num] = -d;
	ret = max(ret, solve(num+1, p));
	return ret;
}

int main () {
	while (~scanf("%d%d",&s,&d)) {
		int p[13] = {};
		int ret = solve(0, p);
		DPRINTF(("%d\n", ret));
		if (ret <= 0) printf("Deficit\n");
		else printf("%d\n", ret);
	}

	return 0;
}



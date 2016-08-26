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
typedef long long ll;
typedef unsigned long long ull;

int N, fw[100001];
void update(int p, int v) {
	for (; p<=100001; p+=p&-p) fw[p] += v;
}

int query(int p) {
	int ret = 0;
	for (; p; p-=p&-p) ret += fw[p];
	return ret;
}

int main () {
	scanf("%d", &N);
	for (int i=0; i<N; ++i) {
		int l, r, ll, rr;
		scanf("%d%d", &l, &r);
		ll = query(l);
		rr = query(r);
		printf("%d", ll + rr);

		update(l, -ll);
		update(l+1, ll+1);
		update(r, -(rr+1));
		update(r+1, rr);
	}
	return 0;
}



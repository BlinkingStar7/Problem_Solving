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

struct node {
	int m, mm;
	node() : m(INF), mm(INF) {}
} a[1<<21];

node find(int a, int b) {

int main () {
	int n, q, base;
	scanf("%d%d", &n, &q);

	for (base=1; base<n; base<<=1);
	for (int i=base; i<base+n; ++i)
		scanf("%d", &a[i].m);

	for (int i=base-1; i>0; --i) {
		a[i].m = min(a[2*i].m, a[2*i+1].m);
		a[i].mm = min(min(a[2*i].mm, a[2*i+1].mm), max(a[2*i].m, a[2*i+1].m));
	}

	for (int i=0; i<q; ++i) {
		int a, b;
		scanf("%d%d", &a,&b);
		node ret = find(a, b);
		printf("%d %d\n", ret.m, ret.mm);
	}
		
	return 0;
}



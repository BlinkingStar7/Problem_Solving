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

const int MAX = 1000001;
long long arr[MAX], st[4*MAX], lazy[4*MAX];
int n, m, k;


long long init(int x, int y, int node) {
	int m = (x+y)/2;
	return st[node] = (x == y) ? arr[x] : init(x, m, 2*node) + init(m+1, y, 2*node+1);
}

void update(int x, int y, int xx, int yy, long long var, int node) {
	if (x >= xx && y <= yy) 
		lazy[node] += var;

	if (lazy[node]) {
		st[node] += (y-x+1)*lazy[node];
		if (x != y) {
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}

	int m = (x+y)/2;
	if (yy < x || xx > y) return;
	if (x >= xx && y <= yy) return;
	update(x, m, xx, yy, var, 2*node); update(m+1, y, xx, yy, var, 2*node+1);
	if (x != y) st[node] = st[2*node] + st[2*node+1];

}

long long query(int x, int y, int xx, int yy, int node) {
	if (yy < x || xx > y) return 0;
	
	if (lazy[node]) {
		st[node] += (y-x+1)*lazy[node];
		if (x != y) {
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}

	int m = (x+y)/2;
	if (x >= xx && y <= yy) return st[node];
	else return query(x, m, xx, yy, 2*node) + query(m+1, y, xx, yy, 2*node+1);
}


int main () {
	scanf("%d%d%d", &n, &m, &k);
	for (int i=0; i<n; ++i)
		scanf("%lld", arr+i);

	init(0, n-1, 1);

	for (int i=0; i<m+k; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		if (a == 1) {
			long long d;
			scanf("%lld", &d);
			update(0, n-1, b-1, c-1, d, 1);
		}
		else
			printf("%lld\n", query(0, n-1, b-1, c-1, 1));
	}

	return 0;
}



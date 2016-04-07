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

int p[1000001], r[1000001], n, m;

void merge(int a, int b) {
	if (a == b) return;
	if (r[a] > r[b]) swap(a, b);
	p[a] = b;
	if (r[a] == r[b]) r[b]++;
}

int f(int a) {
	return a == p[a] ? a : (p[a] = f(p[a]));
}

int main () {
	scanf("%d%d", &n, &m);
	for (int i=0; i<=n; ++i)
		p[i] = i;
	for (int i=0; i<m; ++i) {
		int x,a,b;
		scanf("%d%d%d", &x,&a,&b);
		a = f(a), b = f(b);
		if (x) printf("%s\n", a == b ? "YES" : "NO");
		else merge(a, b);
	}
	return 0;
}



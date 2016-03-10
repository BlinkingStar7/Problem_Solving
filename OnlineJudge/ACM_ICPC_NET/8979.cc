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

struct medal {
	int a, b, c, ind;
} A[1001];

bool compare (int aa, int bb) {
	if (A[aa].a != A[bb].a) return A[aa].a > A[bb].a;
	if (A[aa].b != A[bb].b) return A[aa].b > A[bb].b;
	if (A[aa].c != A[bb].c) return A[aa].c > A[bb].c;
	return false;
}

int main () {
	int n, k, start;
	scanf("%d%d", &n, &k);

	for (int i=0; i<n; ++i) {
		scanf("%d%d%d%d", &A[i].ind, &A[i].a, &A[i].b, &A[i].c);
		if (A[i].ind == k) start = i;
	}


	int ans = 1;
	for (int i=0; i<n; ++i) {
		if (i == start) continue;
		if (compare(i, start)) ++ans;
	}
	printf("%d\n", ans);

	return 0;
}



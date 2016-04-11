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

#define MAX 1001
char A[MAX];
int n, g[MAX], sa[MAX], k;

bool cmp (int a, int b) {
	return g[a] != g[b] ? g[a] < g[b] : g[a+k] < g[b+k];
}

void print() {
	printf("when k = %d\n", k);
	printf("i sa gr str\n"); 

	for (int i=0; i<n; ++i) {
		printf("%1d %2d %2d %s\n", i, sa[i], g[i], A+sa[i]);
	}
	puts("");
}

int main () {
	gets(A);
	n = strlen(A);
	A[n++] = '$';
	A[n] = '\0';

	for (int i=0; i<n; ++i) {
		sa[i] = i;
		g[i] = A[i];
	}

	for (k=1; k<n; k<<=1) {
		sort(sa, sa+n, cmp);

		print();

		int t[MAX];
		t[sa[0]] = 0;
		for (int i=1; i<n; ++i)
			t[sa[i]] = cmp(sa[i-1], sa[i]) ? t[sa[i-1]]+1 : t[sa[i-1]];
		memcpy(g, t, n*sizeof(int));
		print();
	}
	return 0;
}



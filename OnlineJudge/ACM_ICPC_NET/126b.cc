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

#define MAX 1048576
char str[MAX];
int n, sa[MAX], g[MAX], gg[MAX], k, lcp[MAX], r[MAX];

bool cmp (int a, int b) {
	return g[a] != g[b] ? g[a] < g[b] : g[a+k] < g[b+k]; }

int main () {
	gets(str);
	n = strlen(str);

	for (int i=0; i<n; ++i) {
		sa[i] = i;
		g[i] = str[i];
	}

	for (k = 1; k<n; k<<=1) {
		sort(sa, sa+n, cmp);

		gg[sa[0]] = 1;
		for (int i=1; i<n; ++i)
			gg[sa[i]] = cmp(sa[i-1], sa[i]) ? gg[sa[i-1]]+1 : gg[sa[i-1]];
		memcpy(g, gg, n*sizeof(int));
	}


	for (int i=0; i<n; ++i) r[sa[i]] = i;
	for (int k=0, i=0; i<n; ++i, k?--k:0) if (r[i]) {
		int j = sa[r[i]-1];
		while (str[i+k] == str[j+k]) ++k;
		lcp[r[i]] = k;
	}

	for (int i=0; i<n; ++i)
		printf("%d) %s\n", lcp[i], str+sa[i]);

	return 0;
}



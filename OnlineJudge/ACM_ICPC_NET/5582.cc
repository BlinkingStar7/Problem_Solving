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

#define MAX 10000
char str[MAX];
int g[MAX], gg[MAX], sa[MAX], lcp[MAX], r[MAX], n, m, k;
bool cmp (int a, int b) {
	return g[a] != g[b] ? g[a] < g[b] : g[a+k] < g[b+k];
}

inline int owner (int p) {
	return p < m;
}

int main () {
	gets(str);
	m = strlen(str);
	str[m++] = '$';
	gets(str+m);
	n = strlen(str);

	for (int i=0; i<n; ++i) {
		sa[i] = i;
		g[i] = str[i];
	}

	for (k=1; k<n; k<<=1) {
		sort(sa, sa+n, cmp);

		gg[sa[0]] = 1;
		for (int i=1; i<n; ++i)
			gg[sa[i]] = gg[sa[i-1]] + cmp(sa[i-1], sa[i]);
		memcpy(g, gg, n*sizeof(int));
	}

	for (int i=0; i<n; ++i) r[sa[i]] = i;
	for (int i=0, k=0; i<n; ++i, k?--k:0) if (r[i]) {
		while (str[i+k] == str[sa[r[i]-1] + k]) ++k;
		lcp[r[i]] = k;
	}

	int ans = 0;
	for (int i=1; i<n; ++i) {
		if (owner(sa[i-1]) != owner(sa[i]) && lcp[i] > ans) 
			ans = lcp[i];
	}

	printf("%d\n", ans);

	return 0;
}




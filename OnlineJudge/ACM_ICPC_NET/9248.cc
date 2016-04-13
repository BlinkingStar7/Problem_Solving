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

const int MAX = 500001;
char str[MAX];
int sa[MAX], ssa[MAX], c[MAX], lcp[MAX], g[MAX], gg[MAX], n, r[MAX];

void cs(int k) {
	int m = max(n, 300);
	memset(c, 0, sizeof(c));
	for (int i=0; i<n; ++i) c[sa[i]+k<n ? g[sa[i]+k] : 0]++;
	for (int i=1; i<m; ++i) c[i]+=c[i-1];
	for (int i=n-1; i>=0; --i) 
		ssa[--c[sa[i]+k<n ? g[sa[i]+k] : 0]] = sa[i];
	memcpy(sa, ssa, n*sizeof(int));
}

int main () {
	gets(str);
	n = strlen(str);
	for (int i=0; i<n; ++i) {
		sa[i] = i;
		g[i] = str[i];
	}

	for (int k=1; k<n; k <<=1) {
		cs(k);
		cs(0);
		gg[sa[0]] = 1;
		for (int i=1; i<n; ++i)
			gg[sa[i]] = (g[sa[i]] == g[sa[i-1]] && g[sa[i]+k] == g[sa[i-1]+k]) ? gg[sa[i-1]] : gg[sa[i-1]] + 1;
		memcpy (g, gg, n*sizeof(int));
		if (g[sa[n-1]] == n) break;
	}

	for (int i=0; i<n; ++i) r[sa[i]] = i;
	for (int i=0, k=0; i<n; ++i, k?--k:0) if (r[i]) {
		int j = sa[r[i]-1];
		while (str[i+k] == str[j+k]) ++k;
		lcp[r[i]] = k;
	}

	for (int i=0; i<n; ++i) printf("%d%c", sa[i]+1, i == n-1 ? '\n' : ' ');
	putchar('x');
	for (int i=1; i<n; ++i) printf(" %d", lcp[i]);
	return 0;
}



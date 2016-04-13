#include <bits/stdc++.h>
using namespace std;

#define MAX 200001
char str[MAX];
int n, ans, sa[MAX], ssa[MAX], g[MAX], gg[MAX], c[MAX], r[MAX];
void cs(int k) {
	memset(c, 0, sizeof(c));
	int m = max(n, 300);
	for (int i=0; i<n; ++i) c[sa[i]+k < n ? g[sa[i]+k] : 0]++;
	for (int i=1; i<m; ++i) c[i] += c[i-1];
	for (int i=n-1; i>=0; --i)
		ssa[--c[sa[i]+k < n ? g[sa[i]+k] : 0]] = sa[i];
	memcpy(sa, ssa, n*sizeof(int));
}

int main () {
	scanf("%d ", &n);
	gets(str);

	for (int i=0; i<n; ++i) {
		sa[i] = i;
		g[i] = str[i];
	}

	for (int k=1; k<n; k<<=1) {
		cs(k); cs(0);
		gg[sa[0]] = 1;
		for (int i=1; i<n; ++i)
			gg[sa[i]] = gg[sa[i-1]] + 1 - (g[sa[i]] == g[sa[i-1]] && g[sa[i]+k] == g[sa[i-1]+k]);
		memcpy(g, gg, n*sizeof(int));
		if (g[n-1] == n) break;
	}

	for (int i=0; i<n; ++i) r[sa[i]] = i;
	for (int i=0, k=0; i<n; ++i, k?--k:0) if (r[i]) {
		while (str[i+k] == str[sa[r[i]-1]+k]) ++k;
		ans = max(ans, k);
	}

	printf("%d\n", ans);
	return 0;
}



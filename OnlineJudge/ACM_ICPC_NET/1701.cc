#include <bits/stdc++.h>
using namespace std;
char str[5001];
int n, g[5001], gg[5001], sa[5001], lcp[5001], r[5001], k;
bool cmp (int a, int b) {
	return g[a] != g[b] ? g[a] < g[b] : g[a+k] < g[b+k];
}

int main () {
	gets(str);
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
		if (g[n-1] == n) break;
	}

	int ans = 0;
	for (int i=0; i<n; ++i) r[sa[i]] = i;
	for (int i=0, k=0; i<n; ++i, k?--k:0) if (r[i]) {
		while (str[i+k] == str[sa[r[i]-1]+k]) ++k;
		ans = max(ans, lcp[r[i]] = k);
	}

	printf("%d\n", ans);
	return 0;
}



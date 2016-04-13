#include <bits/stdc++.h>
using namespace std;
const int MAX = 1048576;
char str[MAX];
int n, g[MAX], gg[MAX], sa[MAX], r[MAX], k;
long long ans;

bool cmp(int a, int b) {
	return g[a] != g[b] ? g[a] < g[b] : g[a+k] < g[b+k];
}

int main () {
	gets(str);
	n = strlen(str);

	for (int i=0; i<n; ++i) {
		sa[i] = i;
		g[i] = str[i];
	}

	for (k=1; k<n; k <<= 1) {
		sort(sa, sa+n, cmp);
		gg[sa[0]] = 1;
		for (int i=1; i<n; ++i)
			gg[sa[i]] = 1-(g[sa[i]] == g[sa[i-1]] && g[sa[i]+k] == g[sa[i-1]+k]) + gg[sa[i-1]];
		memcpy(g, gg, n*sizeof(int));
		if (g[sa[n-1]] == n) break;
	}

	for (int i=0; i<n; ++i) r[sa[i]] = i;
	for (int i=0, k=0; i<n; ++i, k?--k:0) if (r[i]) {
		while (str[i+k] == str[sa[r[i]-1]+k]) ++k;
		ans += n-i-k;
	}

	printf("%lld\n", ans + n - sa[0]);
	return 0;
}



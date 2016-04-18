#include <bits/stdc++.h>
using namespace std;
const int MAX = 4001;
char str[MAX];
int t, n, sa[MAX], g[MAX], gg[MAX], k;
bool cmp (int a, int b) {
	return g[a] != g[b] ? g[a] < g[b] : g[a+k] < g[b+k];
}

int main () {
	scanf("%d", &t);
	while (t--) {
		int num;
		scanf("%d ", &num);
		gets(str);
		n = strlen(str);

		if (num == 1) {
			printf("%d\n", n);
			continue;
		}

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
			if (g[sa[n-1]] == n) break;
		}

		int ans = 0;
		for (int i=0; i<n-num+1; ++i) {
			int j = i+num-1, cnt=0;
			while (str[sa[i]+cnt]==str[sa[j]+cnt]) ++cnt;
			if (cnt > ans) ans = cnt;
		}
		printf("%d\n", ans);
	}
	return 0;
}



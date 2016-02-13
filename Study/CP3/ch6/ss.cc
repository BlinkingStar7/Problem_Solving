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

#define MAX 10
int sa[MAX], rank[MAX], n, m, k;
char s[MAX], t[MAX];

bool cmp(int a, int b) { 
	printf("comparing %s(%d) with %s(%d)\n", s+a, a, s+b, b);
	printf("rank is \n");
	for (int i=0; i<n; ++i)
		printf("%d", rank[i]);
	puts("");
	printf("a+k = %d, b+k = %d\n",a+k, b+k);
	bool ret = rank[a] != rank[b] ? rank[a] < rank[b] : rank[a+k] < rank[b+k];
	bool eq = rank[a] == rank[b] && rank[a+k] == rank[b+k];
	printf("%s %c %s\n", s+a, ret ? '<' : eq ? '=' : '>', s+b);
	return ret;
}


void consSA() {
	for (int i=0; i<n; ++i) { sa[i] = i, rank[i] = s[i]; }
	rank[n] = -1;
	for (k=1; k<n; k<<=1) {
		sort(sa, sa+n, cmp);
		printf("while k = %d\n", k);
		for (int i=0; i<n; ++i)
			printf("%s\n", s+sa[i]);
		int temp[MAX], r;
		temp[sa[0]] = r = 0;
		for (int i=1; i<n; ++i)
			temp[sa[i]] = (!cmp(sa[i], sa[i-1]) && !cmp(sa[i-1], sa[i]) ? r : ++r);
		memcpy(rank, temp, n*sizeof(int));
		if (rank[sa[n-1]] == n-1) break;
	}
}

int main () {
	n = strlen(gets(s));
	m = strlen(gets(t));
	consSA();
	n = strlen(gets(s)); 
	consSA();

	int lo=0, hi=n-1, mid;
	pii ans;
	while (lo < hi) {
		mid = (lo+hi)/2;
		if (strncmp(s+sa[mid], t, m) >= 0) hi = mid;
		else lo = mid+1;
	}
	if (strncmp(s+sa[lo], t, m) != 0) {printf("not found\n"); return 0;}
	ans.first = lo;
	lo=0, hi=n-1;
	while (lo < hi && ans.first != -1) {
		mid = (lo+hi)/2;
		if (strncmp(s+sa[mid], t, m) > 0) hi = mid;
		else lo = mid+1;
	}
	if (strncmp(s+sa[hi], t, m) != 0) --hi;
	ans.second = hi;
	printf("%s has found in [%d to %d]\n", t, ans.first, ans.second);
	for (int i=ans.first; i<=ans.second; ++i)
		printf("%s\n", s+sa[i]);

	return 0;
}



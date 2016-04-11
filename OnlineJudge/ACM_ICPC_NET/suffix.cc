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

char A[1000001];
int n, sa[1000001], k, g[1000001];

bool cmp2 (int a, int b) {
	return g[a] != g[b] ? g[a] < g[b] : g[a+k] < g[b+k];
}

bool cmp (int a, int b) {
	return strcmp(A+a, A+b) < 0;
}

void print2() {
	for (int i=0; i<n; ++i)
		printf("sa%d, g%d] %s\n", sa[i], g[i], A+sa[i]);
	puts("");
}
void print() {
	for (int i=0; i<n; ++i)
		printf("%d] %s\n", sa[i], A+sa[i]);
	puts("");
}
int main () {
	gets(A);
	n = strlen(A);

	for (int i=0; i<n; ++i)
		sa[i] = i;

	sort(sa, sa+n, cmp);

	print();


	A[n++] = '$'; 
	A[n] = '\0';

	for (int i=0; i<n; ++i) {
		sa[i] = i;
		g[i] = A[i];
	}

	for (k=1; k<n; k<<=1) {
		sort(sa, sa+n, cmp2);
		int t[1000001];

		print2();
		t[0] = 0;
		for (int i=1; i<n; ++i)
			t[i] = cmp2(sa[i-1], sa[i]) ? t[i-1]+1 : t[i-1];
		memcpy (g, t, n*sizeof(int));
		printf("after regroup\n");
		print2();
	}

	print2();
	return 0;
}



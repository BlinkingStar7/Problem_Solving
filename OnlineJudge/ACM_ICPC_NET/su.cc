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
int n, g[MAX], sa[MAX], s[MAX], k;

void countingSort(int k) {
	int c[300]; memset(c, 0, sizeof(c));

	for (int i=0; i<n; ++i)
		c[i+k < n ? g[i+k] : 0]++;
	for (int i=1; i<300; ++i)
		c[i] += c[i-1];

	for (int i=n-1; i>=0; --i)
		s[--c[sa[i]+k < n ? g[sa[i]+k] : 0]] = sa[i];
	memcpy (sa, s, n*sizeof(int));
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

	for (int i=0; i<n; ++i) {
		sa[i] = i;
		g[i] = A[i];
	}

	for (k=1; k<n; k<<=1) {
		countingSort(k);
		countingSort(0);

		print();
		int temp[MAX];
		temp[sa[0]] = 0;
		for (int i=1; i<n; ++i)
			temp[sa[i]] = (g[sa[i]] == g[sa[i-1]] && g[sa[i]+k] == g[sa[i-1]+k]) ?
				temp[sa[i-1]] : temp[sa[i-1]]+1;
		memcpy(g, temp, n*sizeof(int));
		printf("after regroup\n");
		print();
	}
	return 0;
}



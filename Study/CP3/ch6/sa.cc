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
char s[MAX];
int sa[MAX], rank[MAX], n, k;
bool compare2(int a, int b) { return rank[a] != rank[b] ? rank[a] < rank[b] : (a+k < n ? rank[a+k] : 0) < (b+k < n ? rank[b+k] : 0); }
bool compare (int a, int b) { return strcmp(s+a, s+b) < 0; }
void naive() {
	printf("naive implementation!\n");
	for (int i=0; i<n; ++i) sa[i] = i;
	sort(sa, sa+n, compare);
}

void nlog2n() {
	printf("nlog2n implementation!\n");
	for (int i=0; i<n; ++i) {
		sa[i] = i; rank[i] = s[i]; }
	for (k=1; k<n; k<<=1) {
		sort(sa, sa+n, compare2);
		int temp[MAX], r;
		temp[sa[0]] = r = 0;
		for (int i=1; i<n; ++i)
			temp[sa[i]] = !compare2(sa[i], sa[i-1]) && !compare2(sa[i-1], sa[i]) ? r : ++r;
		memcpy(rank, temp, n*sizeof(int));
		if (rank[sa[n-1]] == n-1) break;
	}
}

void print() {
	printf(" i suffix\n");
	for (int i=0; i<n; ++i)
		printf("%2d %s\n", sa[i], s+sa[i]);
	puts("");
}


int main () {
	gets(s);
	n = strlen(s);
	int start = clock();
	naive();
	printf("result= %.3lf(sec)\n", (double)(clock()-start)/CLOCKS_PER_SEC);
	start = clock();
	nlog2n();
	printf("result= %.3lf(sec)\n", (double)(clock()-start)/CLOCKS_PER_SEC);
	
	return 0;
}



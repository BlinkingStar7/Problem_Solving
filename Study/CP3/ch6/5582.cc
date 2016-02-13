#include <bits/stdc++.h>
using namespace std;

#define MAX 4001
char A[MAX], B[MAX];
int a, b, n, k, rank[MAX], sa[MAX], temp[MAX];

bool compare (int a, int b) {
	return rank[a] != rank[b] ? rank[a] < rank[b] : (a+k < n ? rank[a+k] : 0)  < (b+k < n ? rank[b+k] : 0);
}

void print() {
	printf("i sa[i] ra[i] ra[sa[i]+%d]\n", k);
	for (int i=0; i<n; ++i)
		printf("%d %4d %4d %8d\n", i, sa[i], rank[sa[i]], rank[sa[i] + k < n ? sa[i] + k : 0]);
	puts("");
}

void constructSA() {
	int i,r;
	for (i=0; i<n; ++i) rank[i] = A[i];
	for (i=0; i<n; ++i) sa[i] = i;
	for (k=1; k<n; k<<=1) {
		print();
		sort(sa, sa+n, compare);
		temp[sa[0]] = r = 0;
		for (i=1; i<n; ++i)
			temp[sa[i]] = (rank[sa[i]] == rank[sa[i-1]] && rank[sa[i] + k] == rank[sa[i-1] + k] ? r : ++r);
		for (i=0; i<n; ++i)
			rank[i] = temp[i];
		if (rank[sa[n-1]] == n-1) break;
	}
	print();
}

int main() {
	a = strlen(gets(A)), b = strlen(gets(B));
	strcat(A, B);
	n = a + b;
	constructSA();
	return 0;
}



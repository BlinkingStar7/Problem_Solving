#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int N, IDT[1<<18], A[100001];

int findMax (int a, int b) {
	if (a == b) return IDT[a];
	if (a%2) return max(a/2, findMax(a+1,b));
	if (!b%2) return max(b/2, findMax(a,b-1));
	return findMax (a/2, b/2);
}

void update (int a, int b) {
	IDT[a] = b;
	a /= 2;

	while (a >= 1) {
		IDT[a] = max(IDT[a], b);
		a /= 2;
	}
}

int main () {
	cin >> N;
	int max = 0;
	for (int i=0; i<N; ++i) {
		int k;
		scanf("%d", &k);
		scanf("%d", &A[k]);
		if (max < A[k]) max = A[k];
	}

	int base = 1;
	while (base < max) base *= 2;

	for (int i=0; i<100001; ++i) {
		if (A[i]) {
			int n = findMax (base, base+A[i]-1) + 1;
			update (base+A[i]-1, n);
		}
	}

	max = IDT[1];
	cout << N - max << endl;

	int cur = 1;
	for (int i=base; i<base+N; ++i) {
		if (!IDT[i]) continue;
		if (IDT[i] < cur) cout << A[ << endl;
		else ++cur;
	}

	return 0;
}


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

int N, Q, IDT[1<<18];

int Sum (int a, int b) {
	if (a==b) return IDT[a];
	if (a%2) return IDT[a]+Sum(a+1,b);
	if (b%2) return IDT[b]+Sum(a,b-1);
	return Sum (a/2, b/2);
}

void Update (int a, int b) {
	if (a == 0) return;
	IDT[a] += b;
	Update (a/2, b);
}

int main () {
	cin >> N;
	int base = 1;
	while (base < N) base*=2;

	for (int i=0; i<N; ++i)
		scanf("%d", &IDT[base+i]);

	for (int i=base-1; i>=0; --i)
		IDT[i] = IDT[2*i] + IDT[2*i+1];

	cin >> Q;

	for (int i=0; i<Q; ++Q) {
		int k, a, b;
		scanf("%d %d %d", &k, &a, &b);
		if (k==1)
			cout << Sum (base+a-1, base+b-1) << endl;
		else
			Update (a, b-a);
	}

	return 0;
}


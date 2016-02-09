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

int IDT[1<<31 - 1], N;

int sum (int a, int b) {
	if (a == b) return IDT[a];
	if (a%2) return IDT[a] + sum (a+1, b);
	if (!b%2) return IDT[b] + sum (a, b-1);
	return sum (a/2, b/2);
}

void update (int a, int b) {
	IDT[a] = b;
	while ((a>>=1) >= 1)
		IDT[a] = IDT[a*2] + IDT[a*2+1];
}

int main () {
	cin >> N;
	int base;

	for (base=1; base<N; base*=2);

	for (int i=0; i<N; ++i) {
		int k;
		scanf("%d", &k);
		cout << sum (base+k, base+N-1) + 1 << endl;
		update (base+k-1, 1);
	}

	return 0;
}


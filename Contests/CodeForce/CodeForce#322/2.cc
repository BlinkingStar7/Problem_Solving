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

int N, IDT[1<<18];

int findMax (int a, int b) {
	int m=0;
	while(a < b) {
		if (a%2==1) m = max(m, IDT[a++]);
		if (b%2==0) m = max(m, IDT[b--]);
		a>>=1, b>>=1;
	}
	if (a == b) m = max(m, IDT[a]);
	return m;
}


int main () {
	cin >> N;
	int base = 1;
	for (base=1; base<N; base*=2);

	for (int i=0; i<N; ++i)
		scanf("%d", &IDT[base+i]);

	for (int i=base-1; i>0; --i)
		IDT[i] = max (IDT[2*i], IDT[2*i+1]);

	for (int i=0; i<N-1; ++i) {
		int m = findMax (base+i+1, base+N-1);
		if (IDT[base+i] > m) printf("0 ");
		else printf("%d ", m-IDT[base+i]+1);
	}
	printf("0\n");
	return 0;
}


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

int N, K, A[11];

int main () {
	cin >> N >> K;
	int rate = 0;

	for (int i=0; i<N; ++i) {
		int t;
		scanf("%d", &t);
		++A[t%10];
		rate += t/10;
	}

	for (int cur=9; cur >0; --cur) {
		int need = A[cur]*(10-cur);
		if (K >= need) {
			K-= need;
			rate += A[cur];
		}
		else {
			rate += (K/(10-cur));
			K = (K%(10-cur));
		}
	}
	
	rate += (K/10);
	if (rate >= 10*N) rate = 10*N;
	printf("%d\n",rate);

	return 0;
}


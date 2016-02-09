#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
using namespace std;

int N, L, A[1001], IDT[1<<11];

double getSum(int a, int b) {
	int sum=0;
	while (a < b) {
		if (a%2==1) sum += IDT[a++];
		if (b%2==0) sum += IDT[b--];
		a>>=1, b>>=1;
	}
	if (a==b) sum += IDT[a];
	return sum;
}

int main () {
	int C;
	cin >> C;

	while (C--) {
		cin >> N >> L;
		memset(IDT, 0, sizeof(IDT));	
		int base;
		for (base=1; base<N; base*=2);

		for (int i=0; i<N; ++i)
			scanf("%d", &IDT[base+i]);

		for (int i=base-1; i>0; --i)
			IDT[i] = IDT[2*i] + IDT[2*i+1];
		
		double ret = 987654321;

		for (int l=L; l<=N; ++l)
			for (int cur=base+0; cur+l<=base+N; ++cur)
				ret = min (ret, getSum(cur, cur+l-1)/l);

		printf("%.11lf\n", ret);
	}
	return 0;
}


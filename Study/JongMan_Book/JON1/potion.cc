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
#include <set>
using namespace std;

int testNum, N, A[201], B[201];

int GCD (int a, int b) {
	if (a == 0) return b;
	return GCD (b%a, a);
}

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N;
		for (int i=0; i<N; ++i)
			scanf("%d", A+i);
		for (int i=0; i<N; ++i)
			scanf("%d", B+i);

		int gcd = A[0];
		for (int i=1; i<N; ++i)
			gcd = GCD (gcd, A[i]);

		double max = (double)B[0]/A[0];
		int maxI = 0;
		for (int i=1; i<N; ++i) {
			if ((double)B[i]/A[i] > max) {
				maxI= i;
				max = B[i]/A[i];
			}
		}

		if (max <= 1) {
			for (int i=0; i<N; ++i)
				printf("%d ", A[i] - B[i]);
			cout << endl;
			continue;
		}

		int k = gcd;
		while (B[maxI]*gcd > k*A[maxI])
			++k;

		for (int i=0; i<N; ++i)
			printf("%d ", A[i]*k/gcd - B[i]);
		cout << endl;

	}


	return 0;
}


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int A[31][31], N, M;

int main() {
	cin >> N >> M;

	for (int i=0; i<N; ++i)
		for (int j=0; j<=i; ++j)
			if (j == 0 || j == i) A[i][j] = 1;
			else A[i][j] = A[i-1][j-1] + A[i-1][j];
	
	if (M == 1) {
		for (int i=0; i<N; ++i) {
			for (int j=0; j<=i; ++j)
				printf("%s%d", j==0?"":" ", A[i][j]);
			printf("\n");
		}
	}
	else if (M == 2) {
		for (int i=N-1; i>=0; --i) {
			for (int k=0; k<N-1-i; ++k)
				printf(" ");
			for (int j=0; j<=i; ++j)
				printf("%s%d", j==0?"":" ", A[i][j]);
			printf("\n");
		}
	}
	else {
		for (int j=N-1; j>=0; --j) {
			for (int i=N-1; i>=j; --i)
				printf("%d%s", A[i][j], i==j?"":" ");
			printf("\n");
		}
	}

	return 0;
}


